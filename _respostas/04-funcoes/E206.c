// 0035 · Pré-processador: macros e #ifdef
// Exercício E206 · ★☆☆

#include <stdio.h>

#define MAIOR(a, b) ((a) > (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define ENTRE(x, min, max) ((x) >= (min) && (x) <= (max))

int main(void) {
    printf("MAIOR(7, 12) = %d\n", MAIOR(7, 12));
    printf("ABS(-8) = %d\n", ABS(-8));
    printf("ABS(3 - 10) = %d\n", ABS(3 - 10));
    printf("ENTRE(15, 10, 20) = %d\n", ENTRE(15, 10, 20));
    printf("ENTRE(25, 10, 20) = %d\n", ENTRE(25, 10, 20));
    printf("100 / ABS(-5 * 2) = %d\n", 100 / ABS(-5 * 2));
    return 0;
}
