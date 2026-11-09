// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1008 · ★☆☆ · O polinômio pelo jeito de Horner
//
// O preço do frete de uma transportadora segue o polinômio
// p(x) = 2x⁴ - 3x³ + 0x² + 5x - 7, em que x é a distância em centenas de km.
// Os coeficientes ficam num vetor do grau 0 ao 4: c = {-7, 5, 0, -3, 2}.
// Escreva duas funções que calculam p(x) e contam as multiplicações:
//
//   long ingenuo(const int c[], int grau, int x, int *mult)
//     para cada termo k, calcula x elevado a k com um laço (k
//     multiplicações) e multiplica pelo coeficiente (mais 1);
//   long horner(const int c[], int grau, int x, int *mult)
//     r = c[grau]; depois, para k de grau - 1 até 0, r = r * x + c[k].
//
// Mostre os dois para x = 3.
//
//   Saída esperada:
//   Ingênuo: p(3) = 89 com 15 multiplicações
//   Horner:  p(3) = 89 com 4 multiplicações
//
// Dicas:
// 1. Horner reescreve p(x) como (((2x - 3)x + 0)x + 5)x - 7.
// 2. No ingênuo, grau 4 dá 0 + 1 + 2 + 3 + 4 = 10 multiplicações das
//    potências mais 5 dos coeficientes. Para grau n: (n + 1)(n + 2) / 2,
//    O(n²). Horner faz n: O(n).
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
