// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2812 · ★★☆ · Dispersão dupla

#include <stdio.h>

#define M 13

void mostra(const int *t, int m) {
    printf("tabela:");
    for (int j = 0; j < m; j++) {
        if (t[j] == -1) {
            printf(" .");
        } else {
            printf(" %d", t[j]);
        }
    }
    printf("\n");
}

int main(void) {
    int t[M];
    for (int j = 0; j < M; j++) {
        t[j] = -1;
    }
    int chaves[] = {14, 27, 40, 53, 66, 79, 5};
    int total = 0;
    for (int c = 0; c < 7; c++) {
        int k = chaves[c];
        int h1 = k % M, h2 = 1 + k % 11;
        for (int i = 0; i < M; i++) {
            int j = (h1 + i * h2) % M;
            if (t[j] == -1) {
                t[j] = k;
                total += i + 1;
                printf("%2d: passo %2d -> %2d (%d sondagens)\n", k, h2, j, i + 1);
                break;
            }
        }
    }
    mostra(t, M);
    printf("total de sondagens: %d\n", total);
    return 0;
}
