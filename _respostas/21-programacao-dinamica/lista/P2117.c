// Lista · Módulo 21 · Programação dinâmica
// Exercício P2117 · ★★☆ · Pagar com o mínimo de cédulas da carteira

#include <stdio.h>

#define N 8
#define VALOR 64
#define INF 1000

int main(void) {
    const int c[N] = {50, 20, 20, 10, 5, 5, 2, 2};
    int min[VALOR + 1];
    int usou[N][VALOR + 1] = {{0}};
    min[0] = 0;
    for (int s = 1; s <= VALOR; s++) {
        min[s] = INF;
    }
    for (int i = 0; i < N; i++) {
        for (int s = VALOR; s >= c[i]; s--) {
            if (min[s - c[i]] + 1 < min[s]) {
                min[s] = min[s - c[i]] + 1;
                usou[i][s] = 1;
            }
        }
    }
    if (min[VALOR] >= INF) {
        printf("Não dá para pagar R$ %d\n", VALOR);
        return 0;
    }
    printf("Mínimo: %d cédulas\n", min[VALOR]);
    printf("Cédulas:");
    for (int i = N - 1, s = VALOR; i >= 0; i--) {
        if (usou[i][s]) {
            printf(" %d", c[i]);
            s -= c[i];
        }
    }
    printf("\n");
    return 0;
}
