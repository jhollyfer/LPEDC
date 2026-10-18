// 0045 · Ponteiros
// Exercício E269 · ★★★

#include <stdio.h>

int main(void) {
    int a = 3, b = 8;
    int *p = &a, *q = &b;
    printf("início        a = %d, b = %d, *p = %d, *q = %d\n", a, b, *p, *q);

    *p = *q + 1;
    printf("*p = *q + 1   a = %d, b = %d, *p = %d, *q = %d\n", a, b, *p, *q);
    p = q;
    printf("p = q         a = %d, b = %d, *p = %d, *q = %d\n", a, b, *p, *q);
    *p = *p * 2;
    printf("*p = *p * 2   a = %d, b = %d, *p = %d, *q = %d\n", a, b, *p, *q);
    q = &a;
    printf("q = &a        a = %d, b = %d, *p = %d, *q = %d\n", a, b, *p, *q);
    *q -= 4;
    printf("*q -= 4       a = %d, b = %d, *p = %d, *q = %d\n", a, b, *p, *q);
    return 0;
}
