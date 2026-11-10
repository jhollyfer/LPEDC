// 0072 · Notação O: como o custo cresce
// Exercício E430 · ★★☆
//
// A "regra do dobro": rode um algoritmo com n e com 2n e divida os passos.
// Razão perto de 1 (com +1 passo) é O(log n); perto de 2, O(n); perto de 4,
// O(n²). Escreva quatro funções long misterio_a(int n) ... misterio_d(int n),
// que devolvem quantas vezes o laço roda:
//
//   a) for (i = 0; i < n; i += 3)
//   b) for (i = n; i > 0; i /= 2)
//   c) for (i = 0; i < n; i++) for (j = 0; j < n; j += 2)
//   d) for (d = 0; d * d < n; d++)
//
// Escreva também const char *classe(double razao): "O(log n)" se a razão for
// menor que 1.2, "O(raiz n)" se for menor que 1.7, "O(n)" se for menor que 3
// e "O(n^2)" nos outros casos. Mostre, para n = 1000 e n = 2000, os passos, a
// razão e a classe de cada função.
//
//   Saída esperada:
//   a:     334 ->     667  razão 2.00  O(n)
//   b:      10 ->      11  razão 1.10  O(log n)
//   c:  500000 -> 2000000  razão 4.00  O(n^2)
//   d:      32 ->      45  razão 1.41  O(raiz n)
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
