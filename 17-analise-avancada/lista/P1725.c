// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1725 · ★★★ · O método da substituição testado no computador
//
// O merge sort com n qualquer (não só potência de 2) segue
//
//   T(1) = 0,  T(n) = T(⌈n/2⌉) + T(⌊n/2⌋) + n - 1
//
// (n - 1 é o pior caso de comparações ao intercalar). No método da
// substituição, você chuta T(n) <= c · n lg n e prova por indução. O
// computador não prova, mas mostra se o chute é bom e qual c serve.
//
// Escreva um programa que calcule T(n) para todo n de 1 a 1000000 numa
// tabela (de baixo para cima: T[n] só usa índices menores), e mostre:
//
// - T(n) e T(n) / (n lg n) para n = 10, 100, ..., 1000000;
// - o maior valor de T(n) / (n lg n) para 2 <= n <= 1000000, e em que n;
// - a conferência da fórmula exata do pior caso do merge sort:
//   T(n) = n ⌈lg n⌉ - 2^⌈lg n⌉ + 1, para todo n de 1 a 1000000.
//
//   Saída esperada:
//         n          T(n)  T/(n lg n)
//        10            25       0.753
//       100           573       0.862
//      1000          8977       0.901
//     10000        123617       0.930
//    100000       1568929       0.945
//   1000000      18951425       0.951
//   Maior razão: 0.9531, em n = 762546
//   Fórmula n teto(lg n) - 2^teto(lg n) + 1: 0 n errados
//
// Dicas:
// 1. Um vetor de 1 milhão de long ocupa 8 MB: deixe-o global ou static.
// 2. T[n] = T[(n + 1) / 2] + T[n / 2] + n - 1: com inteiros, (n + 1) / 2 é
//    o teto e n / 2 é o chão.
// 3. Para ⌈lg n⌉ e 2^⌈lg n⌉ sem double, ande com uma potência p que dobra
//    enquanto p < n.
// 4. A razão fica abaixo de 1 em todo n: c = 1 serve no chute T(n) <= c n lg n,
//    e o chute fica justo (a razão se aproxima de 1 por baixo).
// 5. Resposta esperada: a fórmula confere em todos os n; com n = 1000000,
//    T = 18951425 e razão 0.951.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>

#define N 1000000

int main(void) {

    return 0;
}
