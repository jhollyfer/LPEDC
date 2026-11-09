// Lista · Módulo 07 · Memória dinâmica
// Exercício P0727 · ★★★ · O determinante por Laplace
//
// O determinante de uma matriz n x n pode ser calculado pela expansão de
// Laplace na primeira linha: det(M) = soma, para j de 0 a n - 1, de
// (-1)^j * M[0][j] * det(menor(M, j)), em que menor(M, j) é a matriz
// (n - 1) x (n - 1) que sobra tirando a linha 0 e a coluna j. Para n = 1, o
// determinante é o próprio número.
//
// Escreva a função recursiva double det(double **m, int n), que monta cada
// menor no heap (matriz dinâmica), calcula e libera. Conte num contador
// global quantas matrizes menores foram alocadas. Calcule o determinante das
// matrizes abaixo (uma 3x3 e uma 4x4) e da identidade 4x4:
//
//   A = | 2 -1  0 |      B = | 1 0 2 -1 |
//       | 1  3  2 |          | 3 0 0  5 |
//       | 0  1  4 |          | 2 1 4 -3 |
//                            | 1 0 5  0 |
//
//   Saída esperada:
//   det A (3x3) = 24, com 6 menores alocados
//   det B (4x4) = 30, com 15 menores alocados
//   det I (4x4) = 1, com 3 menores alocados
//
// Dicas:
// 1. Escreva criar(n) e liberar(m, n) para matrizes double ** quadradas.
// 2. Para montar o menor sem a coluna j: para cada linha i de 1 a n - 1,
//    copie as colunas k != j, com um índice de destino que só anda quando
//    copia.
// 3. Um termo com M[0][j] == 0 não precisa do menor: pule (e o contador
//    mostra a economia).
// 4. O custo cresce como n!: para 4x4, até 4 + 4 * 3 = 16 menores; para
//    10x10, mais de 6 milhões. Por isso, na prática, usa-se eliminação de
//    Gauss.
// 5. Resposta esperada: a saída acima (det A = 24, det B = 30, det I = 1).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
