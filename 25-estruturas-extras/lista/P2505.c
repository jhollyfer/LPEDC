// Lista · Módulo 25 · Estruturas especiais
// Exercício P2505 · ★☆☆ · O caminho da busca na skip list
//
// A skip list das paradas da rodovia (km) já está montada com andares
// escolhidos à mão (sem sorteio). Complete busca(chave): ela desce do
// andar mais alto ao 0 e, a cada vez que o ponteiro AVANÇA, mostra
// [aK]chave, com K o andar em que avançou. No fim, diz se achou.
//
//   Saída esperada:
//   busca 47: [a2]23 [a1]40 -> achou
//   busca 18: [a1]12 -> achou
//   busca 60: [a3]56 -> achou
//   busca 35: [a2]23 [a0]31 -> não tem
//
// Dicas:
// 1. Em cada andar k (de MAX - 1 até 0): enquanto x->prox[k] existe e tem
//    chave menor, avance. Depois do andar 0, o candidato é x->prox[0].
// 2. As paradas e os andares: 5(1) 12(2) 18(1) 23(3) 31(1) 40(2) 47(1)
//    56(4) 60(1). Na busca do 60, um avanço só, no andar 3, até o 56.
// 3. Resposta esperada: o 47 é achado com 2 avanços (23 no andar 2, 40 no
//    andar 1); o 35 não existe.
//
// Escreva sua resposta abaixo:

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

int busca(int chave) {
    printf("busca %d: escreva aqui\n", chave);
    return 0;
}

int main(void) {
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
