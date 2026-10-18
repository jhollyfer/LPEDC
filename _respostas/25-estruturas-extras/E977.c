// 0163 · Skip list
// Exercício E977 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 8

// a moeda: 0 ou 1, sempre a mesma sequência
int moeda(void) {
    static unsigned estado = 42;
    estado = estado * 1103515245u + 12345u;
    return (estado >> 16) & 1;
}

typedef struct NoPal {
    char palavra[24];
    int vezes;
    int andares;
    struct NoPal *prox[MAX];
} NoPal;

// devolve 1 se a palavra é nova, 0 se só contou mais uma vez
int conta(NoPal *cabeca, const char *palavra) {
    NoPal *antes[MAX];
    NoPal *x = cabeca;
    for (int k = MAX - 1; k >= 0; k--) {
        while (x->prox[k] != NULL && strcmp(x->prox[k]->palavra, palavra) < 0) {
            x = x->prox[k];
        }
        antes[k] = x;
    }
    if (x->prox[0] != NULL && strcmp(x->prox[0]->palavra, palavra) == 0) {
        x->prox[0]->vezes++;
        return 0;
    }
    NoPal *novo = malloc(sizeof(NoPal));
    if (novo == NULL) {
        exit(1);
    }
    strcpy(novo->palavra, palavra);
    novo->vezes = 1;
    novo->andares = 1;
    while (novo->andares < MAX && moeda() == 1) {
        novo->andares++;
    }
    for (int k = 0; k < MAX; k++) {
        if (k < novo->andares) {
            novo->prox[k] = antes[k]->prox[k];
            antes[k]->prox[k] = novo;
        } else {
            novo->prox[k] = NULL;
        }
    }
    return 1;
}

int main(void) {
    NoPal cabeca = {.andares = MAX}; // os prox começam todos em NULL
    char palavra[24];
    int diferentes = 0, total = 0;
    while (scanf("%23s", palavra) == 1) {
        diferentes += conta(&cabeca, palavra);
        total++;
    }

    NoPal *p = cabeca.prox[0];
    while (p != NULL) { // mostra e libera pelo andar 0
        printf("%s %d\n", p->palavra, p->vezes);
        NoPal *prox = p->prox[0];
        free(p);
        p = prox;
    }
    printf("%d palavras diferentes, %d no total\n", diferentes, total);
    return 0;
}
