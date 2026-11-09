// Lista · Módulo 25 · Estruturas especiais
// Exercício P2515 · ★★☆ · A busca que sobe a escada
//
// Ache o bug. Esta skip list acha todas as paradas certas, mas a busca
// anda demais: para o km 60, que está logo depois do 56 (o único nó do
// andar 3), ela faz 8 avanços:
//
//   Saída que aparece:
//   km 60: achou, 8 avanço(s)
//   km 47: achou, 6 avanço(s)
//   km 31: achou, 4 avanço(s)
//   km 35: não tem, 5 avanço(s)
//
// A resposta sai certa porque, no andar 0, ela vira uma lista simples. O
// erro está numa linha só da busca. Conserte.
//
//   Saída esperada:
//   km 60: achou, 1 avanço(s)
//   km 47: achou, 2 avanço(s)
//   km 31: achou, 1 avanço(s)
//   km 35: não tem, 2 avanço(s)
//
// Dicas:
// 1. Em que ordem a busca visita os andares? O ônibus expresso serve para
//    o começo da viagem ou para o fim?
// 2. A skip list ganha porque os andares altos pulam MUITO no começo e o
//    andar 0 só acerta os detalhes no fim.
// 3. Resposta esperada: o laço dos andares vai de MAX - 1 até 0; o km 60
//    sai com 1 avanço.
//
// Escreva sua resposta abaixo (conserte o código):

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
    for (int k = 0; k < MAX; k++)
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
