// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2804 · ★☆☆ · Quantos nós em cada nível

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

int profundidade(const No *x) {
    int p = 0;
    while (x->pai != NULL) {
        x = x->pai;
        p++;
    }
    return p;
}

int altura(const No *x) {
    if (x == NULL) {
        return -1;
    }
    int e = altura(x->esq), d = altura(x->dir);
    return 1 + (e > d ? e : d);
}

void mostra_nivel(const No *r, int k, int *conta) {
    if (r == NULL) {
        return;
    }
    mostra_nivel(r->esq, k, conta);
    if (profundidade(r) == k) {
        printf(" %d", r->chave);
        (*conta)++;
    }
    mostra_nivel(r->dir, k, conta);
}

int main(void) {
    int v[] = {60, 30, 90, 20, 45, 75, 40, 50, 95};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = insere(raiz, v[i]);
    }
    int h = altura(raiz);
    for (int k = 0; k <= h; k++) {
        int conta = 0;
        printf("nível %d:", k);
        mostra_nivel(raiz, k, &conta);
        printf(" (%d nós)\n", conta);
    }
    printf("altura: %d\n", h);
    libera(raiz);
    return 0;
}
