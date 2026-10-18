// 0009 · Atribuição, ++ e --
// Exercício E052 · ★★☆
//
// As quatro linhas com operadores compostos rodam em sequência, uma depois
// da outra. Acrescente um printf depois de cada uma, mostrando a instrução
// e o novo valor de x. Depois, para provar que x = x * 2 + y e
// x *= 2 + y são contas diferentes, volte x para 10 e mostre as duas: a
// primeira só no printf, sem guardar; a segunda guardando em x.
//
//   Saída esperada:
//   x *= y + 1 -> 40
//   x -= y - 1 -> 38
//   x /= y + 1 -> 9
//   x %= y + 2 -> 4
//   x * 2 + y = 23
//   x *= 2 + y -> 50
//
// Dicas:
// 1. O composto age sobre toda a expressão da direita: x op= expr é
//    x = x op (expr).
// 2. A divisão é entre int: 38 / 4 dá 9.
// 3. Para o % aparecer no printf, %%.
// 4. Resposta esperada: as seis linhas acima. x *= 2 + y é
//    x = x * (2 + y) = 10 * 5, e não 10 * 2 + 3.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

int main(void) {
    int x = 10, y = 3;
    x *= y + 1;
    x -= y - 1;
    x /= y + 1;
    x %= y + 2;

    return 0;
}
