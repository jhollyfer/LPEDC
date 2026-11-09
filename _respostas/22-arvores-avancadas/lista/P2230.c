// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2230 · ★★★ · Três árvores, mil chaves

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ---------- árvore de busca comum
typedef struct Abb {
    int chave;
    struct Abb *esq, *dir;
} Abb;

void abb_insere(Abb **r, int k) {
    while (*r != NULL) {
        if (k == (*r)->chave) {
            return;
        }
        r = k < (*r)->chave ? &(*r)->esq : &(*r)->dir;
    }
    *r = malloc(sizeof **r);
    if (*r == NULL) {
        exit(1);
    }
    **r = (Abb){k, NULL, NULL};
}

int abb_altura(const Abb *r) {
    if (r == NULL) {
        return 0;
    }
    if (r->esq == NULL) {
        int h = 0;
        while (r != NULL && r->esq == NULL) {
            h++;
            r = r->dir;
        }
        return h + abb_altura(r);
    }
    int e = abb_altura(r->esq), d = abb_altura(r->dir);
    return 1 + (e > d ? e : d);
}

void abb_libera(Abb *r) {
    while (r != NULL) {
        Abb *d = r->dir;
        abb_libera(r->esq);
        free(r);
        r = d;
    }
}

// ---------- rubro-negra esquerdista
typedef struct No {
    int chave;
    bool vermelho; // cor do link que vem do pai
    struct No *esq, *dir;
} No;

bool verm(const No *h) {
    return h != NULL && h->vermelho;
}

No *rot_esq(No *h) {
    No *x = h->dir;
    h->dir = x->esq;
    x->esq = h;
    x->vermelho = h->vermelho;
    h->vermelho = true;
    return x;
}

No *rot_dir(No *h) {
    No *x = h->esq;
    h->esq = x->dir;
    x->dir = h;
    x->vermelho = h->vermelho;
    h->vermelho = true;
    return x;
}

void inverte(No *h) {
    h->vermelho = !h->vermelho;
    h->esq->vermelho = !h->esq->vermelho;
    h->dir->vermelho = !h->dir->vermelho;
}

No *ins(No *h, int k) {
    if (h == NULL) {
        No *n = malloc(sizeof *n);
        if (n == NULL) {
            exit(1);
        }
        *n = (No){k, true, NULL, NULL};
        return n;
    }
    if (k < h->chave) {
        h->esq = ins(h->esq, k);
    } else if (k > h->chave) {
        h->dir = ins(h->dir, k);
    }
    if (verm(h->dir) && !verm(h->esq)) {
        h = rot_esq(h);
    }
    if (verm(h->esq) && verm(h->esq->esq)) {
        h = rot_dir(h);
    }
    if (verm(h->esq) && verm(h->dir)) {
        inverte(h);
    }
    return h;
}

No *insere(No *r, int k) {
    r = ins(r, k);
    r->vermelho = false;
    return r;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int rn_altura(const No *r) {
    if (r == NULL) {
        return 0;
    }
    int e = rn_altura(r->esq), d = rn_altura(r->dir);
    return 1 + (e > d ? e : d);
}

// ---------- árvore B, t = 2
#define T 2
#define MAXC (2 * T - 1)

typedef struct NoB {
    int n;
    int chave[MAXC];
    struct NoB *filho[MAXC + 1];
    bool folha;
} NoB;

NoB *novo_no(bool folha) {
    NoB *x = calloc(1, sizeof *x);
    if (x == NULL) {
        exit(1);
    }
    x->folha = folha;
    return x;
}

void divide(NoB *x, int i) {
    NoB *y = x->filho[i];
    NoB *z = novo_no(y->folha);
    z->n = T - 1;
    for (int j = 0; j < T - 1; j++) {
        z->chave[j] = y->chave[j + T];
    }
    if (!y->folha) {
        for (int j = 0; j < T; j++) {
            z->filho[j] = y->filho[j + T];
        }
    }
    y->n = T - 1;
    for (int j = x->n; j > i; j--) {
        x->filho[j + 1] = x->filho[j];
    }
    x->filho[i + 1] = z;
    for (int j = x->n - 1; j >= i; j--) {
        x->chave[j + 1] = x->chave[j];
    }
    x->chave[i] = y->chave[T - 1];
    x->n++;
}

void b_insere_nao_cheio(NoB *x, int k) {
    int i = x->n - 1;
    if (x->folha) {
        while (i >= 0 && k < x->chave[i]) {
            x->chave[i + 1] = x->chave[i];
            i--;
        }
        x->chave[i + 1] = k;
        x->n++;
        return;
    }
    while (i >= 0 && k < x->chave[i]) {
        i--;
    }
    i++;
    if (x->filho[i]->n == MAXC) {
        divide(x, i);
        if (k > x->chave[i]) {
            i++;
        }
    }
    b_insere_nao_cheio(x->filho[i], k);
}

NoB *b_insere(NoB *r, int k) {
    if (r == NULL) {
        r = novo_no(true);
    }
    if (r->n == MAXC) {
        NoB *s = novo_no(false);
        s->filho[0] = r;
        divide(s, 0);
        b_insere_nao_cheio(s, k);
        return s;
    }
    b_insere_nao_cheio(r, k);
    return r;
}

int b_niveis(const NoB *x) {
    int h = 1;
    while (!x->folha) {
        x = x->filho[0];
        h++;
    }
    return h;
}

void b_libera(NoB *x) {
    if (x != NULL) {
        for (int i = 0; i <= x->n; i++) {
            b_libera(x->filho[i]);
        }
        free(x);
    }
}

// ---------- comparação
void cenario(const char *nome, bool embaralha) {
    Abb *a = NULL;
    No *rn = NULL;
    NoB *b = NULL;
    int s = 0;
    for (int i = 0; i < 1000; i++) {
        int k = embaralha ? s : i;
        s = (s * 41 + 11) % 1000;
        abb_insere(&a, k);
        rn = insere(rn, k);
        b = b_insere(b, k);
    }
    printf("%s: comum %d, rubro-negra %d, B %d níveis\n", nome, abb_altura(a), rn_altura(rn), b_niveis(b));
    abb_libera(a);
    libera(rn);
    b_libera(b);
}

int main(void) {
    cenario("Em ordem", false);
    cenario("Embaralhadas", true);
    return 0;
}
