// Lista · Módulo 25 · Estruturas especiais
// Exercício P2505 · ★☆☆ · O caminho da busca na skip list

#include <stdio.h>
#include <stdlib.h>

#define MAX 4

typedef struct No {
    int chave;
    int andares;
    struct No *prox[MAX];
} No;

No cabeca; // a cabeça tem MAX andares e não guarda chave

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

// mostra cada parada da busca: em que andar e em que nó o ponteiro está
int busca(int chave) {
    No *x = &cabeca;
    printf("busca %d:", chave);
    for (int k = MAX - 1; k >= 0; k--) {
        while (x->prox[k] != NULL && x->prox[k]->chave < chave) {
            x = x->prox[k];
            printf(" [a%d]%d", k, x->chave);
        }
    }
    x = x->prox[0];
    int achou = x != NULL && x->chave == chave;
    printf(" -> %s\n", achou ? "achou" : "não tem");
    return achou;
}

int main(void) {
    // km das paradas da rodovia e quantos andares cada uma tem
    int paradas[][2] = {{5, 1}, {12, 2}, {18, 1}, {23, 3}, {31, 1}, {40, 2}, {47, 1}, {56, 4}, {60, 1}};
    for (int k = 0; k < 9; k++) insere(paradas[k][0], paradas[k][1]);
    busca(47);
    busca(18);
    busca(60);
    busca(35);

    No *x = cabeca.prox[0];
    while (x != NULL) {
        No *seguinte = x->prox[0];
        free(x);
        x = seguinte;
    }
    return 0;
}
