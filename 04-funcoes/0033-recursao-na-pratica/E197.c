// 0033 · Recursão na prática: Fibonacci, Hanói e Euclides
// Exercício E197 · ★★★
//
// Exponenciação rápida. Para calcular 3^13 dá para multiplicar 3 por ele mesmo
// 12 vezes, mas existe um atalho: se o expoente é par, x^e = (x^(e/2))²; se é
// ímpar, x^e = x * x^(e-1). Escreva duas funções recursivas que contam as
// multiplicações numa global:
//
//   long long pot_lenta(long long x, int e)    x * pot_lenta(x, e - 1)
//   long long pot_rapida(long long x, int e)   o atalho acima
//
// Mostre o resultado e o número de multiplicações de cada uma para 3^13 e 2^60.
//
//   Saída esperada:
//   lenta:  3^13 = 1594323 (13 multiplicações)
//   rápida: 3^13 = 1594323 (6 multiplicações)
//   lenta:  2^60 = 1152921504606846976 (60 multiplicações)
//   rápida: 2^60 = 1152921504606846976 (9 multiplicações)
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
