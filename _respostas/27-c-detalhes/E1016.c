// 0170 · Precedência e ordem de avaliação
// Exercício E1016 · ★☆☆

#include <stdio.h>

int main(void) {
    printf("100 / 10 / 5 = %d   ((100 / 10) / 5) = %d\n", 100 / 10 / 5, ((100 / 10) / 5));
    printf("2 - 3 - 4 = %d   ((2 - 3) - 4) = %d\n", 2 - 3 - 4, ((2 - 3) - 4));
    printf("2 * 3 %% 4 = %d   ((2 * 3) %% 4) = %d\n", 2 * 3 % 4, ((2 * 3) % 4));

    int a, b, c;
    a = b = c = 7; // a = (b = (c = 7))
    printf("a = b = c = 7 -> a = %d, b = %d, c = %d\n", a, b, c);

    int x = 5;
    x -= 1 + 2; // x = x - (1 + 2)
    printf("x -= 1 + 2 -> x = %d\n", x);
    return 0;
}
