// 0061 · Matriz dinâmica
// Exercício E364 · ★★☆
//
// Monte o triângulo de Pascal com 6 linhas usando um vetor de ponteiros em
// que a linha i tem exatamente i + 1 elementos (nada de matriz quadrada com
// metade desperdiçada). As pontas de cada linha valem 1 e cada número de
// dentro é a soma dos dois de cima: p[i][j] = p[i-1][j-1] + p[i-1][j].
//
//   Saída esperada:
//   1
//   1 1
//   1 2 1
//   1 3 3 1
//   1 4 6 4 1
//   1 5 10 10 5 1
//   Elementos guardados: 21
//
// Dicas:
// 1. p[i] = malloc((i + 1) * sizeof *p[i]);
// 2. Uma matriz 6 x 6 guardaria 36 números; o triângulo guarda
//    1 + 2 + ... + 6.
// 3. Resposta esperada: a saída acima. Para liberar, o laço é o mesmo: cada
//    p[i] e depois p.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
