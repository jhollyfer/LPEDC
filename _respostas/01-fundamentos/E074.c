// 0013 · Conversão e cast
// Exercício E074 · ★☆☆
//
// Resposta: a = 7; b = 3.0; c = 3.5; d = -7; e = 'B'; f = 3.0; g = 3.

#include <stdio.h>

int main(void) {
    int a = 7.9;
    double b = 7 / 2;
    double c = 7 / 2.0;
    int d = -7.9;
    char e = 66;
    double f = (double) (7 / 2);
    int g = (int) 3.999;

    printf("a = %d\n", a);
    printf("b = %.1f\n", b);
    printf("c = %.1f\n", c);
    printf("d = %d\n", d);
    printf("e = %c\n", e);
    printf("f = %.1f\n", f);
    printf("g = %d\n", g);
    return 0;
}
