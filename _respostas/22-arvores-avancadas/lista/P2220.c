// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2220 · ★★☆ · O tamanho de sapato mais próximo

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

int piso(const No *r, int x) {
    int melhor = -1;
    while (r != NULL) {
        if (r->chave == x) {
            return x;
        }
        if (r->chave < x) {
            melhor = r->chave;
            r = r->dir;
        } else {
            r = r->esq;
        }
    }
    return melhor;
}

int teto(const No *r, int x) {
    int melhor = -1;
    while (r != NULL) {
        if (r->chave == x) {
            return x;
        }
        if (r->chave > x) {
            melhor = r->chave;
            r = r->esq;
        } else {
            r = r->dir;
        }
    }
    return melhor;
}

int main(void) {
    const int estoque[8] = {34, 35, 37, 38, 40, 41, 43, 45};
    No *r = NULL;
    for (int i = 0; i < 8; i++) {
        r = insere(r, estoque[i]);
    }
    const int pedido[5] = {36, 33, 46, 40, 42};
    for (int i = 0; i < 5; i++) {
        int p = piso(r, pedido[i]), t = teto(r, pedido[i]);
        printf("Pedido %d: ", pedido[i]);
        if (p < 0) {
            printf("piso nenhum, ");
        } else {
            printf("piso %d, ", p);
        }
        if (t < 0) {
            printf("teto nenhum\n");
        } else {
            printf("teto %d\n", t);
        }
    }
    libera(r);
    return 0;
}
