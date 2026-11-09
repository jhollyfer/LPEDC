// Lista · Módulo 25 · Estruturas especiais
// Exercício P2513 · ★★☆ · A parada desativada

#include <stdbool.h>
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

// desce guardando o último nó antes da chave em cada andar e desliga o nó
// de TODOS os andares dele antes de liberar
bool remove_chave(int chave) {
    No *antes[MAX], *x = &cabeca;
    for (int k = MAX - 1; k >= 0; k--) {
        while (x->prox[k] != NULL && x->prox[k]->chave < chave) x = x->prox[k];
        antes[k] = x;
    }
    No *alvo = x->prox[0];
    if (alvo == NULL || alvo->chave != chave) return false;
    for (int k = 0; k < alvo->andares; k++) antes[k]->prox[k] = alvo->prox[k];
    free(alvo);
    return true;
}

void mostra(void) {
    for (int k = MAX - 1; k >= 0; k--) {
        printf("  andar %d:", k);
        for (No *x = cabeca.prox[k]; x != NULL; x = x->prox[k]) printf(" %d", x->chave);
        printf("\n");
    }
}

int main(void) {
    int paradas[][2] = {{5, 1}, {12, 2}, {18, 1}, {23, 3}, {31, 1}, {40, 2}, {47, 1}, {56, 4}, {60, 1}};
    for (int k = 0; k < 9; k++) insere(paradas[k][0], paradas[k][1]);
    int sai[] = {23, 56, 35, 5};
    for (int k = 0; k < 4; k++) {
        bool ok = remove_chave(sai[k]);
        printf("remove %d: %s\n", sai[k], ok ? "removida" : "não existe");
    }
    mostra();
    No *x = cabeca.prox[0];
    while (x != NULL) {
        No *seguinte = x->prox[0];
        free(x);
        x = seguinte;
    }
    return 0;
}
