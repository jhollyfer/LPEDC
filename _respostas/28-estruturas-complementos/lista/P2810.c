// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2810 · ★☆☆ · Pigeonhole dos dados

#include <stdio.h>

int main(void) {
    int v[] = {3, 6, 1, 3, 5, 2, 6, 6, 4, 1, 3, 5, 6, 2, 3};
    int n = 15;
    int casa[6] = {0};
    for (int i = 0; i < n; i++) {
        casa[v[i] - 1]++;
    }
    printf("frequências:");
    for (int c = 0; c < 6; c++) {
        printf(" %d:%d", c + 1, casa[c]);
    }
    int k = 0;
    for (int c = 0; c < 6; c++) {
        for (int j = 0; j < casa[c]; j++) {
            v[k++] = c + 1;
        }
    }
    printf("\nordenados:");
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
    return 0;
}
