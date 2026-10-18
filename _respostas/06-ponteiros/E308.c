// 0052 · Ponteiros e vetores
// Exercício E308 · ★☆☆
//
// Resposta: a) 20; b) 50; c) 23; d) 40; e) 60; f) 0x2010 (0x2004 + 3 * 4);
// g) 40; h) 30; i) 3.

#include <stdio.h>

int main(void) {
    int v[6] = {10, 20, 30, 40, 50, 60};
    int *p = v + 1;

    printf("a) %d\n", *p);
    printf("b) %d\n", *(p + 3));
    printf("c) %d\n", *p + 3);
    printf("d) %d\n", p[2]);
    printf("e) %d\n", *(v + 5));
    printf("f) p = %p, p + 3 = %p\n", (void *)p, (void *)(p + 3));
    p += 2;
    printf("g) %d\n", *p);
    printf("h) %d\n", p[-1]);
    printf("i) %td\n", p - v);
    return 0;
}
