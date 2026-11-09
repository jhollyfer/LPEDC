// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2805 · ★☆☆ · O fator de cada nó

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *esq, *dir, *pai;
} No;

No *insere(No *raiz, int chave) {
    No *pai = NULL, *x = raiz;
    while (x != NULL) {
        pai = x;
        x = chave < x->chave ? x->esq : x->dir;
    }
    No *z = malloc(sizeof(No));
    if (z == NULL) {
        exit(1);
    }
    z->chave = chave;
    z->esq = z->dir = NULL;
    z->pai = pai;
    if (pai == NULL) {
        return z;
    }
    if (chave < pai->chave) {
        pai->esq = z;
    } else {
        pai->dir = z;
    }
    return raiz;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int altura(const No *x) {
    if (x == NULL) {
        return -1;
    }
    int e = altura(x->esq), d = altura(x->dir);
    return 1 + (e > d ? e : d);
}

void fatores(const No *r, bool *avl) {
    if (r == NULL) {
        return;
    }
    fatores(r->esq, avl);
    int f = altura(r->esq) - altura(r->dir);
    printf(" %d(%d)", r->chave, f);
    if (f < -1 || f > 1) {
        *avl = false;
    }
    fatores(r->dir, avl);
}

void relata(const No *raiz) {
    bool avl = true;
    printf("fatores:");
    fatores(raiz, &avl);
    printf("\n%s\n", avl ? "é AVL" : "não é AVL");
}

int main(void) {
    int v[] = {60, 30, 90, 20, 45, 75, 40, 50, 95};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = insere(raiz, v[i]);
    }
    relata(raiz);
    raiz = insere(raiz, 55);
    relata(raiz);
    libera(raiz);
    return 0;
}
