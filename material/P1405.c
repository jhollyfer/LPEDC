// Lista · Módulo 14 · Árvores
// Exercício P1405 · ★☆☆ · O heap de lances do leilão
//
// No leilão online, o maior lance tem que estar sempre à mão. Os lances
// chegam nesta ordem: 120, 340, 200, 510, 90, 450, 380. Escreva
// void insere(int heap[], int *n, int x), que coloca x no fim de um heap de
// MÁXIMO (raiz em heap[0], pai de i em (i - 1) / 2) e faz ele subir enquanto
// for maior que o pai. Mostre o vetor depois de cada inserção.
//
//   Saída esperada:
//   depois do 120: 120
//   depois do 340: 340 120
//   depois do 200: 340 120 200
//   depois do 510: 510 340 200 120
//   depois do 90: 510 340 200 120 90
//   depois do 450: 510 340 450 120 90 200
//   depois do 380: 510 340 450 120 90 200 380
//
// Dicas:
// 1. int i = (*n)++; heap[i] = x; e depois o while (i > 0 && pai < filho).
// 2. O 510 entra no índice 3, troca com o 120 (índice 1) e depois com o 340
//    (índice 0): sobe 2 níveis, O(log n).
// 3. O vetor do heap NÃO está ordenado; só a raiz é garantidamente o maior.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
