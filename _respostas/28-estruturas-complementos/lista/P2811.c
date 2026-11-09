// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2811 · ★★☆ · Sondagem quadrática

#include <stdio.h>

#define M 11

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
    int placas[] = {23, 45, 12, 34, 56, 9, 1};
    int total = 0;
    for (int p = 0; p < 7; p++) {
        int k = placas[p];
        for (int i = 0; i < M; i++) {
            int j = (k % M + i * i) % M;
            if (t[j] == -1) {
                t[j] = k;
                total += i + 1;
                printf("%2d -> vaga %2d (%d sondagens)\n", k, j, i + 1);
                break;
            }
        }
    }
    mostra(t, M);
    printf("total de sondagens: %d\n", total);
    return 0;
}
