// 0140 · Mochila 0/1
// Exercício E836 · ★☆☆

#include <stdio.h>

#define N 5
#define W 9

int main(void) {
    const char *nome[N + 1] = {"", "barraca", "saco de dormir", "fogareiro",
                               "comida", "câmera"};
    int peso[N + 1] = {0, 4, 2, 3, 3, 1};
    int valor[N + 1] = {0, 12, 8, 9, 10, 5};
    int t[N + 1][W + 1];

    for (int c = 0; c <= W; c++) {
        t[0][c] = 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int c = 0; c <= W; c++) {
            t[i][c] = t[i - 1][c];
            if (peso[i] <= c && valor[i] + t[i - 1][c - peso[i]] > t[i][c]) {
                t[i][c] = valor[i] + t[i - 1][c - peso[i]];
            }
        }
    }
    printf("Valor máximo: %d\n", t[N][W]);

    int c = W, peso_total = 0;
    printf("Leva:\n");
    for (int i = N; i >= 1; i--) {
        if (t[i][c] != t[i - 1][c]) { // mudou: o item i entrou
            printf("  %s (%d kg)\n", nome[i], peso[i]);
            c -= peso[i];
            peso_total += peso[i];
        }
    }
    printf("Peso usado: %d kg\n", peso_total);
    return 0;
}
