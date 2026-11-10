// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0512 · ★★☆ · A tabela de distâncias é simétrica?
//
// Uma transportadora de Manaus guarda as distâncias (em km) entre 4 bases numa
// matriz 4x4. Se a ida e a volta têm a mesma distância, a matriz é SIMÉTRICA:
// m[i][j] == m[j][i] para todo i e j. Uma delas foi digitada com erro:
//
//   int d1[4][4] = {{0, 12, 30, 8}, {12, 0, 25, 17},
//                   {30, 25, 0, 21}, {8, 17, 21, 0}};
//   int d2[4][4] = {{0, 12, 30, 8}, {12, 0, 25, 17},
//                   {30, 52, 0, 21}, {8, 17, 21, 0}};
//
// Escreva bool simetrica(int m[4][4], int erro[2]), que devolve se a matriz
// é simétrica e, quando não for, guarda em erro[0] e erro[1] a linha e a coluna
// do primeiro par diferente (com coluna maior que a linha).
// Mostre também a soma dos números acima da diagonal principal (que, numa
// tabela simétrica, é a soma de todas as distâncias, cada uma uma vez só):
//
//   Saída esperada:
//   d1: simétrica, soma acima da diagonal = 113 km
//   d2: NÃO simétrica em [1][2] (25 x 52)
//
// Dicas:
// 1. Só precisa olhar acima da diagonal: j começa em i + 1. Cada par (i, j)
//    é comparado com (j, i) uma vez só.
// 2. Um vetor passado para a função é alterado no original: é assim que
//    erro[0] e erro[1] voltam para o main.
// 3. Acima da diagonal principal, j > i.
// 4. Resposta esperada: d1 simétrica com soma 113; d2 não simétrica, primeiro
//    erro em [1][2] (25 x 52).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int d1[4][4] = {{0, 12, 30, 8}, {12, 0, 25, 17}, {30, 25, 0, 21}, {8, 17, 21, 0}};
    int d2[4][4] = {{0, 12, 30, 8}, {12, 0, 25, 17}, {30, 52, 0, 21}, {8, 17, 21, 0}};
    (void) d1, (void) d2; // apague esta linha quando escrever

    return 0;
}
