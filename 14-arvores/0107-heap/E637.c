// 0107 · Heap e fila de prioridade
// Exercício E637 · ★☆☆
//
// No papel, diga quais destes vetores são heaps de máximo. Para cada um que
// não for, aponte um pai menor que um filho (com os índices).
//
//   a) [95 60 80 20 60 75 10]
//   b) [50 40 45 42 10 30 44]
//   c) [7]
//   d) [10 20]
//   e) [9 8 7 6 5 4 3 2 1]
//
// Dicas:
// 1. Para cada i a partir de 1, compare v[i] com o pai v[(i - 1) / 2].
// 2. Desenhar a árvore ajuda: os índices vão nível por nível.
// 3. Resposta esperada: a) sim (o 60 repetido não atrapalha: pai >= filho);
//    b) não: v[3] = 42 é filho de v[1] = 40; c) sim (um elemento só);
//    d) não: v[1] = 20 é filho de v[0] = 10; e) sim: todo vetor decrescente
//    é heap.
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>

int main(void) {

    return 0;
}
