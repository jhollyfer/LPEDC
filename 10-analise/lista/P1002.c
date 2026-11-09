// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1002 · ★☆☆ · A planilha inteira contra a diagonal
//
// Uma planilha quadrada n x n tem, na linha i e coluna j, o valor i + j
// (contando de 0). Escreva duas funções que recebem n (até 8) e um ponteiro
// para um contador de somas:
//
//   int soma_tudo(int m[8][8], int n, int *somas)       // todas as células
//   int soma_diagonal(int m[8][8], int n, int *somas)   // só m[i][i]
//
// Cada "s += ..." conta 1 soma. Preencha a matriz no main e mostre os
// resultados para n = 2, 4 e 8.
//
//   Saída esperada:
//   n = 2: soma 4 (4 somas), diagonal 2 (2 somas)
//   n = 4: soma 48 (16 somas), diagonal 12 (4 somas)
//   n = 8: soma 448 (64 somas), diagonal 56 (8 somas)
//
// Dicas:
// 1. soma_tudo tem dois for aninhados de 0 a n - 1: n · n somas, O(n²).
// 2. soma_diagonal tem um for só: n somas, O(n).
// 3. Repare: dobrar n multiplica por 4 as somas da planilha inteira e só
//    por 2 as da diagonal.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
