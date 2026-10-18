// 0009 · Atribuição, ++ e --
// Exercício E052 · ★★☆

#include <stdio.h>

int main(void) {
    int x = 10, y = 3;
    x *= y + 1;    // 10 * 4
    printf("x *= y + 1 -> %d\n", x);
    x -= y - 1;    // 40 - 2
    printf("x -= y - 1 -> %d\n", x);
    x /= y + 1;    // 38 / 4, divisão inteira
    printf("x /= y + 1 -> %d\n", x);
    x %= y + 2;    // 9 % 5
    printf("x %%= y + 2 -> %d\n", x);

    x = 10;
    printf("x * 2 + y = %d\n", x * 2 + y); // 20 + 3
    x *= 2 + y;                            // 10 * (2 + 3)
    printf("x *= 2 + y -> %d\n", x);
    return 0;
}
