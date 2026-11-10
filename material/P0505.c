// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0505 · ★☆☆ · A grade de horários deitada
//
// A escola guarda quantas aulas cada professor dá em cada dia, numa matriz
// 3x4 (linhas: Ana, Beto, Cris; colunas: seg, ter, qua, qui):
//
//   int aulas[3][4] = {{2, 4, 0, 3}, {1, 1, 5, 2}, {3, 0, 2, 4}};
//
// A secretaria quer a tabela "deitada": uma linha por dia e uma coluna por
// professor. Monte a TRANSPOSTA t[4][3] (t[j][i] = aulas[i][j]) e mostre as
// duas, cada número com %3d:
//
//   Saída esperada:
//   Por professor (3x4):
//     2  4  0  3
//     1  1  5  2
//     3  0  2  4
//   Por dia (4x3):
//     2  1  3
//     4  1  0
//     0  5  2
//     3  2  4
//
// Dicas:
// 1. A transposta de uma matriz L x C é C x L: o que era linha vira coluna.
// 2. Dois for: o de fora em i (0 a 2), o de dentro em j (0 a 3), e a linha
//    t[j][i] = aulas[i][j]; dentro.
// 3. Para mostrar, os limites mudam: t tem 4 linhas de 3 colunas.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int aulas[3][4] = {{2, 4, 0, 3}, {1, 1, 5, 2}, {3, 0, 2, 4}};
    (void) aulas; // apague esta linha quando escrever

    return 0;
}
