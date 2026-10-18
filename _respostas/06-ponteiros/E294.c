// 0049 · Ponteiro para ponteiro
// Exercício E294 · ★★★
//
// Resposta: x=10 y=3 *p=3 *q=10 **pp=10.
//
//   linha            x    y    p    q    pp
//   início           1    2    &x   &y   &p
//   **pp = 10        10   2    &x   &y   &p
//   *pp = q          10   2    &y   &y   &p
//   **pp += 5        10   7    &y   &y   &p
//   pp = &q          10   7    &y   &y   &q
//   *q = **pp * 2    10   14   &y   &y   &q
//   *pp = &x         10   14   &y   &x   &q
//   *p = 3           10   3    &y   &x   &q

#include <stdio.h>

int main(void) {
    int x = 1, y = 2;
    int *p = &x, *q = &y;
    int **pp = &p;

    **pp = 10;
    *pp = q;
    **pp += 5;
    pp = &q;
    *q = **pp * 2;
    *pp = &x;
    *p = 3;

    printf("x=%d y=%d *p=%d *q=%d **pp=%d\n", x, y, *p, *q, **pp);
    return 0;
}
