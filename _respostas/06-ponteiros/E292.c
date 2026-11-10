// 0049 · Ponteiro para ponteiro
// Exercício E292 · ★★☆

#include <stdio.h>

void aponta_maior(int *a, int *b, int **res) {
    if (*a > *b) {
        *res = a;
    } else {
        *res = b;
    }
}

int main(void) {
    int lance1 = 870, lance2 = 640;
    int *vencedor = NULL;

    aponta_maior(&lance1, &lance2, &vencedor);
    printf("Maior lance: R$ %d\n", *vencedor);
    return 0;
}
