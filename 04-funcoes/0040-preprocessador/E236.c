// 0040 · Pré-processador: macros e #ifdef
// Exercício E236 · ★☆☆
//
// Escreva três macros à prova de precedência e teste com os valores abaixo:
//
//   MAIOR(a, b)          o maior dos dois
//   ABS(x)               o valor absoluto
//   ENTRE(x, min, max)   1 se min <= x <= max, senão 0
//
//   Saída esperada:
//   MAIOR(7, 12) = 12
//   ABS(-8) = 8
//   ABS(3 - 10) = 7
//   ENTRE(15, 10, 20) = 1
//   ENTRE(25, 10, 20) = 0
//   100 / ABS(-5 * 2) = 10
//
// Dicas:
// 1. Use o ternário: ((a) > (b) ? (a) : (b)).
// 2. Parênteses em cada parâmetro e em volta de tudo. O último teste quebra se
//    faltar o par de fora.
// 3. Resposta esperada: a saída acima. ABS(x) fica ((x) < 0 ? -(x) : (x)).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
