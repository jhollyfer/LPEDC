// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2209 · ★☆☆ · O trabalho escondido da rubro-negra

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int n_esq = 0, n_dir = 0, n_inv = 0;

typedef struct No {
    int chave;
    bool vermelho; // cor do link que vem do pai
    struct No *esq, *dir;
} No;

bool verm(const No *h) {
    return h != NULL && h->vermelho;
}

No *rot_esq(No *h) {
    n_esq++;
    No *x = h->dir;
    h->dir = x->esq;
    x->esq = h;
    x->vermelho = h->vermelho;
    h->vermelho = true;
    return x;
}

No *rot_dir(No *h) {
    n_dir++;
    No *x = h->esq;
    h->esq = x->dir;
    x->dir = h;
    x->vermelho = h->vermelho;
    h->vermelho = true;
    return x;
}

void inverte(No *h) {
    n_inv++;
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

int altura(const No *r) {
    if (r == NULL) {
        return 0;
    }
    int e = altura(r->esq), d = altura(r->dir);
    return 1 + (e > d ? e : d);
}

int main(void) {
    No *r = NULL;
    for (int k = 1; k <= 15; k++) {
        r = insere(r, k);
    }
    printf("Raiz: %d\n", r->chave);
    printf("Rotações à esquerda: %d\n", n_esq);
    printf("Rotações à direita: %d\n", n_dir);
    printf("Inversões de cor: %d\n", n_inv);
    printf("Altura: %d nós\n", altura(r));
    libera(r);
    return 0;
}
