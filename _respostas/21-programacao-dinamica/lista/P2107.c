// Lista · Módulo 21 · Programação dinâmica
// Exercício P2107 · ★☆☆ · Plantões sem dois seguidos

#include <stdio.h>

#define N 9

int main(void) {
    const int valor[N + 1] = {0, 180, 250, 160, 300, 120, 220, 400, 150, 210};
    int ganho[N + 1];
    ganho[0] = 0;
    ganho[1] = valor[1];
    for (int i = 2; i <= N; i++) {
        int sem = ganho[i - 1], com = valor[i] + ganho[i - 2];
        ganho[i] = com > sem ? com : sem;
    }
    printf("Ganho máximo: R$ %d\n", ganho[N]);
    int dias[N], nd = 0;
    for (int i = N; i >= 1;) {
        if (i >= 2 && ganho[i] == ganho[i - 1]) {
            i--;
        } else {
            dias[nd++] = i;
            i -= 2;
        }
    }
    printf("Dias:");
    for (int k = nd - 1; k >= 0; k--) {
        printf(" %d", dias[k]);
    }
    printf("\n");
    return 0;
}
