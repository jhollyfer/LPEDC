// Lista · Módulo 25 · Estruturas especiais
// Exercício P2513 · ★★☆ · A parada desativada
//
// As paradas da rodovia estão numa skip list com andares escolhidos à mão.
// A concessionária desativou algumas. Complete remove_chave(chave): desça
// como na busca guardando em antes[k] o último nó antes da chave em cada
// andar; se a chave existe, desligue o nó de TODOS os andares dele e
// libere. Remova 23, 56, 35 (não existe) e 5, e mostre os andares.
//
//   Saída esperada:
//   remove 23: removida
//   remove 56: removida
//   remove 35: não existe
//   remove 5: removida
//     andar 3:
//     andar 2:
//     andar 1: 12 40
//     andar 0: 12 18 31 40 47 60
//
// Dicas:
// 1. O alvo é antes[0]->prox[0]. Para k de 0 até alvo->andares - 1:
//    antes[k]->prox[k] = alvo->prox[k].
// 2. Desligar só o andar 0 deixaria ponteiros dos andares de cima para um
//    nó já liberado (use-after-free na próxima busca).
// 3. Resposta esperada: sem o 56 e o 23, os andares 3 e 2 ficam vazios; o
//    andar 0 fica 12 18 31 40 47 60.
//
// Escreva sua resposta abaixo:

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

bool remove_chave(int chave) {
    (void)chave; // apague esta linha e escreva a remoção
    return false;
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
