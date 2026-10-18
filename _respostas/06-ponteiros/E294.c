// 0049 · Ponteiro para ponteiro
// Exercício E294 · ★★★

#include <stdio.h>

int main(void) {
    int x = 1, y = 2;
    int *p = &x, *q = &y;
    int **pp = &p;
    printf("início          x=%d y=%d *p=%d *q=%d **pp=%d\n", x, y, *p, *q, **pp);

    **pp = 10;
    printf("**pp = 10       x=%d y=%d *p=%d *q=%d **pp=%d\n", x, y, *p, *q, **pp);
    *pp = q;
    printf("*pp = q         x=%d y=%d *p=%d *q=%d **pp=%d\n", x, y, *p, *q, **pp);
    **pp += 5;
    printf("**pp += 5       x=%d y=%d *p=%d *q=%d **pp=%d\n", x, y, *p, *q, **pp);
    pp = &q;
    printf("pp = &q         x=%d y=%d *p=%d *q=%d **pp=%d\n", x, y, *p, *q, **pp);
    *q = **pp * 2;
    printf("*q = **pp * 2   x=%d y=%d *p=%d *q=%d **pp=%d\n", x, y, *p, *q, **pp);
    *pp = &x;
    printf("*pp = &x        x=%d y=%d *p=%d *q=%d **pp=%d\n", x, y, *p, *q, **pp);
    *p = 3;
    printf("*p = 3          x=%d y=%d *p=%d *q=%d **pp=%d\n", x, y, *p, *q, **pp);
    return 0;
}
