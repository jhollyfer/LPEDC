// 0138 · Memoização
// Exercício E827 · ★★★
//
// Um robô de armazém anda numa grade de 16 x 16 corredores, só para baixo ou
// para a direita, da posição (0, 0) até (15, 15). Uma fileira de prateleiras
// ocupa a linha 8 inteira, menos a coluna 0, que é a única passagem. A função
// caminhos(i, j) conta, com memoização, de quantos jeitos o robô vai de
// (i, j) até o destino.
//
// O programa dá a resposta certa, mas faz quase 1,5 milhão de chamadas
// para uma grade de 256 posições, e com uma grade de 30 x 30 ele não
// termina nunca. Há UM erro de propósito, e ele não é de sintaxe: a
// memoização "funciona" para umas posições e não para outras. Ache e
// conserte.
//
//   Saída hoje:
//   54264 caminhos, 1471165 chamadas
//
//   Saída esperada (depois de consertar):
//   54264 caminhos, 481 chamadas
//
// Dicas:
// 1. Quantos caminhos saem de (3, 5) e chegam ao destino? Lembre que o robô
//    não anda para a esquerda nem para cima.
// 2. Para essas posições, o que fica guardado em memo[i][j]? E o que o teste
//    "já calculei?" conclui ao ver esse valor?
// 3. Um vetor global começa zerado. O "não calculado" precisa ser um valor
//    que nunca é resposta.
// 4. Resposta esperada: o memo usa 0 como "não calculado", mas 0 é a
//    resposta de toda posição acima das prateleiras fora da coluna 0; essas
//    são recalculadas a cada visita. Encha o memo com -1 no main e teste
//    memo[i][j] != -1.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define TAM 16

int prateleira[TAM][TAM];
long long memo[TAM][TAM]; // global: começa com tudo 0
long long chamadas = 0;

long long caminhos(int i, int j) {
    chamadas++;
    if (i >= TAM || j >= TAM || prateleira[i][j]) {
        return 0; // saiu da grade ou bateu na prateleira
    }
    if (i == TAM - 1 && j == TAM - 1) {
        return 1; // chegou
    }
    if (memo[i][j] != 0) {
        return memo[i][j]; // já calculado
    }
    memo[i][j] = caminhos(i + 1, j) + caminhos(i, j + 1);
    return memo[i][j];
}

int main(void) {
    for (int j = 1; j < TAM; j++) {
        prateleira[8][j] = 1; // a fileira, com a passagem na coluna 0
    }
    long long total = caminhos(0, 0);
    printf("%lld caminhos, %lld chamadas\n", total, chamadas);
    return 0;
}
