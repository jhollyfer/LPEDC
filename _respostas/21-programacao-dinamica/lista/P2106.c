// Lista · Módulo 21 · Programação dinâmica
// Exercício P2106 · ★☆☆ · A maior fila em ordem de altura

#include <stdio.h>

#define N 10

int main(void) {
    const int alt[N] = {121, 135, 118, 140, 127, 132, 145, 124, 150, 138};
    int lis[N], melhor = 0;
    for (int i = 0; i < N; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (alt[j] < alt[i] && lis[j] + 1 > lis[i]) {
                lis[i] = lis[j] + 1;
            }
        }
        if (lis[i] > melhor) {
            melhor = lis[i];
        }
    }
    printf("lis:");
    for (int i = 0; i < N; i++) {
        printf(" %d", lis[i]);
    }
    printf("\n");
    printf("Maior fila crescente: %d crianças\n", melhor);
    return 0;
}
