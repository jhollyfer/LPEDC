// 0119 · Shell sort
// Exercício E709 · ★☆☆
//
// Antes de ordenar, o shell sort escolhe os saltos. Escreva a função
// void mostra_saltos(int n), que mostra os saltos de Knuth (h = 3h + 1) que
// o shell sort do texto usa para um vetor de n elementos, na ordem em que
// eles são usados (do maior para o 1). Chame para n = 10, 100, 1000 e
// 1000000.
//
//   Saída esperada:
//   n = 10: 4 1
//   n = 100: 40 13 4 1
//   n = 1000: 364 121 40 13 4 1
//   n = 1000000: 797161 265720 88573 29524 9841 3280 1093 364 121 40 13 4 1
//
// Dicas:
// 1. Primeiro suba: comece com h = 1 e faça h = 3 * h + 1 enquanto
//    h < n / 3.
// 2. Depois desça com h /= 3 até h chegar a 0, mostrando cada h.
// 3. Um milhão de elementos pede só 13 rodadas.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
