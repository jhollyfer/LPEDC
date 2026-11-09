// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2803 · ★☆☆ · O grau de cada nó

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

int grau(const No *x) {
    return (x->esq != NULL) + (x->dir != NULL);
}

void percorre(const No *r, int *maior, int *folhas) {
    if (r == NULL) {
        return;
    }
    percorre(r->esq, maior, folhas);
    int g = grau(r);
    printf(" %d(%d)", r->chave, g);
    if (g > *maior) {
        *maior = g;
    }
    if (g == 0) {
        (*folhas)++;
    }
    percorre(r->dir, maior, folhas);
}

int main(void) {
    int v[] = {60, 30, 90, 20, 45, 75, 40, 50, 95};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = insere(raiz, v[i]);
    }
    int maior = 0, folhas = 0;
    printf("em ordem:");
    percorre(raiz, &maior, &folhas);
    printf("\ngrau da árvore: %d | folhas: %d\n", maior, folhas);
    libera(raiz);
    return 0;
}
