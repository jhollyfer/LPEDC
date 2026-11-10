// 0117 · Limite inferior da ordenação
// Exercício E700 · ★★☆
//
// O pior caso do merge sort tem recorrência própria: as metades têm ⌈n/2⌉ e
// ⌊n/2⌋ elementos e intercalar custa no máximo n - 1 comparações:
// W(1) = 0 e W(n) = W(⌈n/2⌉) + W(⌊n/2⌋) + (n - 1). Escreva pior_merge(n),
// recursiva (a própria recorrência, sem ordenar nada), e teto_log2(x) com
// inteiros, como no E697. Mostre para n de 1 a 16 o limite ⌈log₂ n!⌉, o pior
// caso do merge sort e o do insertion sort, n(n - 1)/2.
//
//   Saída esperada:
//    n  limite  merge  insertion
//    1       0      0          0
//    2       1      1          1
//    3       3      3          3
//    4       5      5          6
//    5       7      8         10
//    6      10     11         15
//    7      13     14         21
//    8      16     17         28
//    9      19     21         36
//   10      22     25         45
//   11      26     29         55
//   12      29     33         66
//   13      33     37         78
//   14      37     41         91
//   15      41     45        105
//   16      45     49        120
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
