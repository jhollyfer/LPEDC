// 0117 · Limite inferior da ordenação
// Exercício E700 · ★★☆
//
// O pior caso do merge sort tem a sua própria recorrência: as duas metades
// têm ⌈n/2⌉ e ⌊n/2⌋ elementos, e intercalar n elementos custa no máximo
// n - 1 comparações:
//
//   W(1) = 0
//   W(n) = W(⌈n/2⌉) + W(⌊n/2⌋) + (n - 1)
//
// Escreva pior_merge(n) recursiva, que é a própria recorrência (não
// precisa ordenar nada), e teto_log2(x) com inteiros, como no E697. Mostre
// para n de 1 a 16 o limite ⌈log₂ n!⌉, o pior caso do merge sort e o do
// insertion sort, n(n - 1)/2:
//
//   Saída esperada:
//    n  limite  merge  insertion
//    1       0      0          0
//    2       1      1          1
//    3       3      3          3
//    4       5      5          6
//    5       7      8         10
//    6      10     11         15
//   ...
//   12      29     33         66
//   ...
//   16      45     49        120
//
// Dicas:
// 1. Em C, ⌈n/2⌉ é (n + 1) / 2 e ⌊n/2⌋ é n / 2 (divisão inteira).
// 2. O fatorial cabe em unsigned long long até n = 20.
// 3. Resposta esperada: a tabela acima. O merge sort é ótimo até n = 4 e
//    depois fica a poucas comparações do limite (4 a mais em n = 16). O
//    insertion se afasta cada vez mais: Θ(n²) contra Θ(n log n).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
