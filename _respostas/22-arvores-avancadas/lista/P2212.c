// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2212 · ★★☆ · A árvore 2-3 escondida na rubro-negra

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

void mostra23(const No *h, int nivel) {
    if (h == NULL) {
        return;
    }
    if (verm(h->esq)) {
        printf("%*s[%d %d]\n", 2 * nivel, "", h->esq->chave, h->chave);
        mostra23(h->esq->esq, nivel + 1);
        mostra23(h->esq->dir, nivel + 1);
        mostra23(h->dir, nivel + 1);
    } else {
        printf("%*s[%d]\n", 2 * nivel, "", h->chave);
        mostra23(h->esq, nivel + 1);
        mostra23(h->dir, nivel + 1);
    }
}

int main(void) {
    No *r = NULL;
    for (int k = 10; k <= 90; k += 10) {
        r = insere(r, k);
    }
    mostra23(r, 0);
    libera(r);
    return 0;
}
