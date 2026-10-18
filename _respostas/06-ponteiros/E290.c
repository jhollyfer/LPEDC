// 0049 · Ponteiro para ponteiro
// Exercício E290 · ★☆☆

#include <stdio.h>

int main(void) {
    int x = 5;
    int *p = &x;
    int **pp = &p;

    printf("x    = %d\n", x);
    printf("p    = %p\n", (void *)p);
    printf("*p   = %d\n", *p);
    printf("pp   = %p\n", (void *)pp);
    printf("*pp  = %p\n", (void *)*pp);
    printf("**pp = %d\n", **pp);
    printf("&pp  = %p\n", (void *)&pp);
    printf("&*pp = %p\n", (void *)&*pp);
    printf("comparações: %d %d %d %d\n", *pp == p, *pp == &x, &*pp == pp, **pp == x);

    **pp = 8;
    printf("x agora = %d\n", x);
    return 0;
}
