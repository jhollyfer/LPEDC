// 0123 · Quickselect
// Exercício E736 · ★★☆
//
// Quem cuida de servidores olha os PERCENTIS: o p90 é o tempo que 90% das
// requisições não ultrapassam. Gere 50 tempos de resposta, em ms, com
//
//   t[i] = 30 + (i * 37) % 50 * 4 + (i % 9 == 0 ? 600 : 0)
//
// Escreva o quickselect (Lomuto, pivô v[r]) e int percentil(int v[], int n,
// int pct), que devolve o valor da posição teto(pct * n / 100) - 1 da ordem
// crescente. Mostre p50, p90 e p99. Depois ordene com qsort e confira as
// posições 24, 44 e 49.
//
//   Saída esperada:
//   p50: 138 ms
//   p90: 630 ms
//   p99: 826 ms
//   conferindo: 138, 630 e 826
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
