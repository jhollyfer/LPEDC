// 0009 · Atribuição, ++ e --
// Exercício E052 · ★★☆
//
// Resposta: 40, 38, 9 e 4. x *= 2 + y não é o mesmo que x = x * 2 + y: o
// composto põe a direita entre parênteses, x = x * (2 + y).

#include <stdio.h>

int main(void) {
    int x = 10, y = 3;
    x *= y + 1;  // 10 * 4
    printf("%d\n", x);
    x -= y - 1;  // 40 - 2
    printf("%d\n", x);
    x /= y + 1;  // 38 / 4, divisão inteira
    printf("%d\n", x);
    x %= y + 2;  // 9 % 5
    printf("%d\n", x);
    return 0;
}
