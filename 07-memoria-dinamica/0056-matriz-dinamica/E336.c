// 0056 · Matriz dinâmica
// Exercício E336 · ★★★
//
// Escreva a função
//
//   int **multiplicar(int **a, int la, int ca, int **b, int lb, int cb);
//
// que devolve uma matriz NOVA la x cb com o produto a * b, ou NULL se as
// dimensões não combinarem (ca precisa ser igual a lb). Teste com
//
//   A (2 x 3)    B (3 x 2)
//   1 2 3        7  8
//   4 5 6        9 10
//                11 12
//
// e depois tente A * A (2 x 3 vezes 2 x 3).
//
//   Saída esperada:
//   58 64
//   139 154
//   A * A: dimensões incompatíveis
//
// Dicas:
// 1. c[i][j] é a soma de a[i][k] * b[k][j] para k de 0 a ca - 1.
// 2. Reaproveite criar_matriz e liberar_matriz do A111. Para preencher A e
//    B, copie de matrizes fixas int [2][3] e int [3][2].
// 3. Resposta esperada: a saída acima. Libere A, B e o produto; o NULL de
//    A * A não precisa de free (free(NULL) também não faria mal).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
