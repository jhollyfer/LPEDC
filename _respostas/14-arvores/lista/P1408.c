// Lista · Módulo 14 · Árvores
// Exercício P1408 · ★☆☆ · A altura que contava nós
//
// Resposta: o módulo conta a altura em ARESTAS. A árvore vazia tem altura
// -1 (e não 0), assim a folha fica com 1 + (-1) = 0. Com return 0 no caso
// base, cada nó ganhava 1 a mais.

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int km;
    struct No *esq, *dir;
} No;

No *novo(int km, No *esq, No *dir) {
    No *p = malloc(sizeof(No));
    if (p == NULL) {
        exit(1);
    }
    p->km = km;
    p->esq = esq;
    p->dir = dir;
    return p;
}

int altura(const No *r) {
    if (r == NULL) {
        return -1;
    }
    int he = altura(r->esq), hd = altura(r->dir);
    return 1 + (he > hd ? he : hd);
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    No *folha = novo(12, NULL, NULL);
    No *raiz = novo(30, novo(18, novo(5, NULL, NULL), NULL), novo(44, NULL, novo(60, novo(52, NULL, NULL), NULL)));

    printf("altura da folha: %d\n", altura(folha));
    printf("altura da árvore: %d\n", altura(raiz));
    printf("altura da vazia: %d\n", altura(NULL));
    libera(folha);
    libera(raiz);
    return 0;
}
