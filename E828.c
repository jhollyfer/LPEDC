// 0138 · Memoização
// Exercício E828 · ★★★
//
// Na Mega-Sena você escolhe 6 dezenas entre 60. O número de jogos possíveis
// é C(60, 6), e a recorrência do triângulo de Pascal calcula isso sem
// fatorial nenhum (60! não cabe em tipo nenhum do C):
//
//   C(n, k) = C(n - 1, k - 1) + C(n - 1, k),   com C(n, 0) = C(n, n) = 1
//
// (a dezena n entra no jogo ou não entra). A recursão pura faria
// 2 x C(60, 6) - 1, uns 100 milhões de chamadas. Escreva a função
//
//   long long comb(int n, int k)
//
// com memoização numa matriz memo[61][61] e um contador global de chamadas.
// Calcule C(60, 6) e depois, zerando o contador mas SEM limpar o memo,
// C(60, 30). No fim, conte quantas posições do memo foram preenchidas.
//
//   Saída esperada:
//   Mega-Sena: C(60, 6) = 50063860 (649 chamadas)
//   chance de acertar com um jogo: 1 em 50063860
//   C(60, 30) = 118264581564861424 (1441 chamadas novas)
//   subproblemas guardados no memo: 1044
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
