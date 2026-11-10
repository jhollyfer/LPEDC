// 0115 · Teorema mestre
// Exercício E689 · ★★★
//
// Escreva multiplica4 (quatro produtos de metades) e multiplica3 (Karatsuba:
// p0 = a0·b0, p2 = a1·b1, p1 = (a0 + a1)·(b0 + b1) - p0 - p2, resultado p0 +
// p1·x^h + p2·x^(2h), h = n/2), recursivas, "void f(const long a[], const
// long b[], int n, long r[])", com n potência de 2, r com 2n - 1
// coeficientes, n = 1 multiplicando direto e um contador global de
// multiplicações. Teste a = 1 2 3 4 e b = 5 6 7 8; depois n = 64, 128 e 256
// com x[i] = i % 10 e y[i] = (3 * i) % 7, conferindo que os resultados são
// iguais.
//
//   Saída esperada:
//   4 produtos: 5 16 34 60 61 52 32  (16 multiplicações)
//   3 produtos: 5 16 34 60 61 52 32  (9 multiplicações)
//   n =  64:   4096 contra   729 multiplicações, mesmo resultado
//   n = 128:  16384 contra  2187 multiplicações, mesmo resultado
//   n = 256:  65536 contra  6561 multiplicações, mesmo resultado
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
