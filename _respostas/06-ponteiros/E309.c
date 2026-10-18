// 0052 · Juntando tudo: o ranking da feira
// Exercício E309 · ★★☆

#include <stdio.h>

void troca(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void ordena3(int *a, int *b, int *c) {
    if (*a > *b) {
        troca(a, b);
    }
    if (*a > *c) {
        troca(a, c);
    }
    if (*b > *c) {
        troca(b, c);
    }
}

int main(void) {
    int ana = 31, bia = 7, caio = 19;

    ordena3(&ana, &bia, &caio);
    printf("%d %d %d\n", ana, bia, caio);

    int x = 3, y = 2, z = 1;
    ordena3(&x, &y, &z);
    printf("%d %d %d\n", x, y, z);
    return 0;
}
