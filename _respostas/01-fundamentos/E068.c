// 0012 · Aritmética
// Exercício E068 · ★☆☆
//
// Resposta: a) 13; b) 20; c) 3; d) 2; e) -3; f) -2; g) 2 (2 * 3 = 6, e
// 6 % 4 = 2); h) 3.4.

#include <stdio.h>

int main(void) {
    printf("a) %d\n", 7 + 3 * 2);
    printf("b) %d\n", (7 + 3) * 2);
    printf("c) %d\n", 17 / 5);
    printf("d) %d\n", 17 % 5);
    printf("e) %d\n", -17 / 5);
    printf("f) %d\n", -17 % 5);
    printf("g) %d\n", 2 * 3 % 4);
    printf("h) %.1f\n", 17.0 / 5);
    return 0;
}
