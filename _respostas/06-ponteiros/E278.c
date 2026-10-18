// 0047 · Ponteiros e vetores
// Exercício E278 · ★☆☆

#include <stdio.h>

int main(void) {
    int v[6] = {10, 20, 30, 40, 50, 60};
    int *p = v + 1;

    printf("a) %d\n", *p);
    printf("b) %d\n", *(p + 3));
    printf("c) %d\n", *p + 3);
    printf("d) %d\n", p[2]);
    printf("e) p = %p, p + 3 = %p\n", (void *)p, (void *)(p + 3));

    p += 2;

    printf("f) %d\n", *p);
    printf("g) %d\n", p[-1]);
    printf("h) %td\n", p - v);
    return 0;
}
