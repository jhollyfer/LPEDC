// 0050 · Ponteiros
// Exercício E299 · ★★★
//
// Resposta: a = 5, b = 16, *p = 16, *q = 5.
//
//   linha              a    b    p    q
//   início             3    8    &a   &b
//   *p = *q + 1        9    8    &a   &b
//   p = q              9    8    &b   &b
//   *p = *p * 2        9    16   &b   &b
//   q = &a             9    16   &b   &a
//   *q -= 4            5    16   &b   &a

#include <stdio.h>

int main(void) {
    int a = 3, b = 8;
    int *p = &a, *q = &b;

    *p = *q + 1;
    p = q;
    *p = *p * 2;
    q = &a;
    *q -= 4;

    printf("a = %d, b = %d, *p = %d, *q = %d\n", a, b, *p, *q);
    return 0;
}
