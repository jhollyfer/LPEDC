// Lista · Módulo 14 · Árvores
// Exercício P1408 · ★☆☆ · A altura que contava nós
//
// A árvore abaixo guarda os quilômetros das paradas de uma linha de ônibus.
// A função altura tem um erro de propósito: ela não segue a convenção do
// módulo (altura em ARESTAS, folha com altura 0, árvore vazia com -1). Rode,
// veja os números errados e conserte.
//
//   Saída esperada (depois do conserto):
//   altura da folha: 0
//   altura da árvore: 3
//   altura da vazia: -1
//
// Dicas:
// 1. Antes do conserto, tudo sai 1 a mais e a vazia sai 0.
// 2. Só o caso base está errado. Quanto vale 1 + max(he, hd) numa folha, se
//    a altura de NULL for -1?
// 3. Resposta esperada: if (r == NULL) return -1; e a saída fica igual à de
//    cima.
//
// Escreva sua resposta abaixo (conserte o código):

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
        return 0;
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
