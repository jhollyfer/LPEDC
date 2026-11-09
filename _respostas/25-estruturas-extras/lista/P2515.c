// Lista · Módulo 25 · Estruturas especiais
// Exercício P2515 · ★★☆ · A busca que sobe a escada

#include <stdio.h>
#include <stdlib.h>

#define MAX 4

typedef struct No {
    int chave;
    int andares;
    struct No *prox[MAX];
} No;

No cabeca;

void insere(int chave, int andares) {
    No *antes[MAX], *x = &cabeca;
    for (int k = MAX - 1; k >= 0; k--) {
        while (x->prox[k] != NULL && x->prox[k]->chave < chave) x = x->prox[k];
        antes[k] = x;
    }
    No *novo = malloc(sizeof(No));
    if (novo == NULL) exit(1);
    novo->chave = chave;
    novo->andares = andares;
    for (int k = 0; k < MAX; k++) {
        novo->prox[k] = NULL;
        if (k < andares) {
            novo->prox[k] = antes[k]->prox[k];
            antes[k]->prox[k] = novo;
        }
    }
}

int busca(int chave, int *avancos) {
    No *x = &cabeca;
    *avancos = 0;
    for (int k = MAX - 1; k >= 0; k--) // o conserto: do andar mais ALTO para o 0
        while (x->prox[k] != NULL && x->prox[k]->chave < chave) {
            x = x->prox[k];
            (*avancos)++;
        }
    x = x->prox[0];
    return x != NULL && x->chave == chave;
}

int main(void) {
    int paradas[][2] = {{5, 1}, {12, 2}, {18, 1}, {23, 3}, {31, 1}, {40, 2}, {47, 1}, {56, 4}, {60, 1}};
    for (int k = 0; k < 9; k++) insere(paradas[k][0], paradas[k][1]);
    int procura[] = {60, 47, 31, 35};
    for (int k = 0; k < 4; k++) {
        int av;
        int ok = busca(procura[k], &av);
        printf("km %d: %s, %d avanço(s)\n", procura[k], ok ? "achou" : "não tem", av);
    }
    No *x = cabeca.prox[0];
    while (x != NULL) {
        No *seguinte = x->prox[0];
        free(x);
        x = seguinte;
    }
    return 0;
}
