// Lista · Módulo 25 · Estruturas especiais
// Exercício P2514 · ★★☆ · Skip list contra lista simples
//
// O catálogo tem 2000 códigos (3, 6, 9, ..., 6000) numa skip list com
// moeda de semente fixa. O programa já insere tudo e tem busca(chave),
// que devolve quantas chaves ela comparou. Estenda o main: busque todos os
// 2000 códigos, some as comparações e guarde a pior; ao lado, mostre o que
// uma lista simples ordenada gastaria (a chave da posição c custa c
// comparações), sem montar a lista: use a fórmula da soma 1 + 2 + ... + N.
//
//   Saída esperada:
//   Skip list: 40255 comparações, média 20.1, pior 35
//   Lista simples: 2001000 comparações, média 1000.5, pior 2000
//
// Dicas:
// 1. A soma de 1 a N é N(N + 1)/2. Guarde em long.
// 2. A média da skip list fica perto de 2 log2(N): para N = 2000, uns 22.
// 3. Resposta esperada: média 20.1 e pior 35 na skip list, contra média
//    1000.5 e pior 2000 na lista simples.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define MAX 16
#define N 2000

typedef struct No {
    int chave;
    struct No *prox[MAX];
} No;

No cabeca;
unsigned semente = 7;

int moeda(void) {
    semente = semente * 1103515245u + 12345u;
    return (semente >> 16) & 1;
}

void insere(int chave) {
    int andares = 1;
    while (andares < MAX && moeda() == 1) andares++;
    No *antes[MAX], *x = &cabeca;
    for (int k = MAX - 1; k >= 0; k--) {
        while (x->prox[k] != NULL && x->prox[k]->chave < chave) x = x->prox[k];
        antes[k] = x;
    }
    No *novo = malloc(sizeof(No));
    if (novo == NULL) exit(1);
    novo->chave = chave;
    for (int k = 0; k < MAX; k++) {
        novo->prox[k] = NULL;
        if (k < andares) {
            novo->prox[k] = antes[k]->prox[k];
            antes[k]->prox[k] = novo;
        }
    }
}

// devolve quantas chaves foram comparadas (cada olhada em x->prox[k])
int busca(int chave) {
    int passos = 0;
    No *x = &cabeca;
    for (int k = MAX - 1; k >= 0; k--) {
        while (x->prox[k] != NULL) {
            passos++;
            if (x->prox[k]->chave >= chave) break;
            x = x->prox[k];
        }
    }
    return passos;
}

int main(void) {
    for (int c = 1; c <= N; c++) insere(3 * c); // códigos 3, 6, ..., 6000
    printf("busca do 3000: %d comparações\n", busca(3000));

    No *x = cabeca.prox[0];
    while (x != NULL) {
        No *seguinte = x->prox[0];
        free(x);
        x = seguinte;
    }
    return 0;
}
