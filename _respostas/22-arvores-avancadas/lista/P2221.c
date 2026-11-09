// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2221 · ★★★ · A rubro-negra que se fiscaliza

#include <math.h>
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

int fiscal(const No *h) {
    if (h == NULL) {
        return 0;
    }
    if (verm(h->dir)) {
        return -1;
    }
    if (verm(h) && verm(h->esq)) {
        return -1;
    }
    int e = fiscal(h->esq), d = fiscal(h->dir);
    if (e < 0 || d < 0 || e != d) {
        return -1;
    }
    return e + (h->vermelho ? 0 : 1);
}

int altura(const No *r) {
    if (r == NULL) {
        return 0;
    }
    int e = altura(r->esq), d = altura(r->dir);
    return 1 + (e > d ? e : d);
}

int main(void) {
    No *r = NULL;
    int s = 0;
    for (int n = 1; n <= 1000; n++) {
        r = insere(r, s);
        s = (s * 41 + 11) % 1000;
        if (n % 200 == 0) {
            int ap = fiscal(r);
            printf("n = %4d: %s, altura %d, altura preta %d, limite %.1f\n", n,
                   ap >= 0 ? "aprovada" : "REPROVADA", altura(r), ap, 2 * log2(n + 1.0));
        }
    }
    libera(r);
    return 0;
}
