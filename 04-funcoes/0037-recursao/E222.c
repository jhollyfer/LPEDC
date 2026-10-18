// 0037 · Recursão
// Exercício E222 · ★★★
//
// A calculadora velha da loja só sabe somar e subtrair. Escreva
// "int multiplicar(int a, int b)", recursiva, que só usa + e - (nada de *),
// e que funciona com b positivo, zero e NEGATIVO.
//
//   Saída esperada:
//   7 x 4 = 28
//   7 x -3 = -21
//   -5 x 6 = -30
//   9 x 0 = 0
//
// Dicas:
// 1. Para b > 0: a * b = a + a * (b - 1). Caso base: b == 0 dá 0.
// 2. Com b negativo, b - 1 se afasta do zero e a recursão nunca para. Para
//    b < 0, ande para o outro lado: a * b = a * (b + 1) - a.
// 3. Resposta esperada: 28, -21, -30 e 0. São três ramos: b == 0, b > 0 e
//    b < 0. Em todos, b chega mais perto de 0 a cada chamada.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
