// 0008 · Conversão e cast
// Exercício E044 · ★☆☆
//
// b e f guardavam 3.0: a divisão 7 / 2 era entre dois int e já dava 3
// antes de virar double.

#include <stdio.h>

int main(void) {
    int a = 7.9;                  // quero 7
    double b = 7 / 2.0;           // quero 3.5 (era 7 / 2)
    double c = 7 / 2.0;           // quero 3.5
    int d = -7.9;                 // quero -7
    char e = 66;                  // quero 'B'
    double f = (double) 7 / 2;    // quero 3.5 (o cast vem antes da divisão)
    int g = (int) 3.999;          // quero 3

    printf("a = %d\n", a);
    printf("b = %.1f\n", b);
    printf("c = %.1f\n", c);
    printf("d = %d\n", d);
    printf("e = %c\n", e);
    printf("f = %.1f\n", f);
    printf("g = %d\n", g);
    return 0;
}
