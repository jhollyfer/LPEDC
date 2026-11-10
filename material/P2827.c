// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2827 · ★★★ · A AVL mais magra de cada altura
//
// A AVL com o menor número de nós para a altura h (a árvore de Fibonacci)
// tem N(h) = N(h - 1) + N(h - 2) + 1 nós, com N(0) = 1 e N(1) = 2. Calcule
// N(h) de baixo para cima, para h de 0 a 12, e mostre também o máximo,
// 2^(h+1) - 1, e a razão h / log2(N(h) + 1), que cresce devagar em direção a
// 1,44: a AVL mais torta é no máximo uns 44% mais alta que a perfeita.
//
//   Saída esperada:
//    h | mínimo | máximo | h / log2(N + 1)
//    0 |      1 |      1 | 0.00
//    1 |      2 |      3 | 0.63
//    2 |      4 |      7 | 0.86
//    3 |      7 |     15 | 1.00
//    4 |     12 |     31 | 1.08
//    5 |     20 |     63 | 1.14
//    6 |     33 |    127 | 1.18
//    7 |     54 |    255 | 1.21
//    8 |     88 |    511 | 1.24
//    9 |    143 |   1023 | 1.26
//   10 |    232 |   2047 | 1.27
//   11 |    376 |   4095 | 1.29
//   12 |    609 |   8191 | 1.30
//
// Dicas:
// 1. Um vetor long N[13] preenchido num for, como no Fibonacci da
//    programação dinâmica.
// 2. log2 está em <math.h>; para h = 0, a razão é 0.
// 3. N(h) = F(h + 3) - 1, onde F é a sequência de Fibonacci.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>

int main(void) {

    return 0;
}
