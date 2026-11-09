// Lista · Módulo 21 · Programação dinâmica
// Exercício P2118 · ★★☆ · O drone que gasta menos bateria

#include <stdio.h>

#define L 5
#define C 5
#define INF 1000000

int main(void) {
    const int g[L][C] = {
        {3, 2, 4, 1, 5},
        {1, -1, 2, -1, 2},
        {4, 1, 3, 1, 1},
        {2, -1, 5, 2, -1},
        {6, 2, 1, 3, 2},
    };
    int custo[L][C];
    for (int l = 0; l < L; l++) {
        for (int c = 0; c < C; c++) {
            if (g[l][c] < 0) {
                custo[l][c] = INF;
                continue;
            }
            int melhor = (l == 0 && c == 0) ? 0 : INF;
            if (l > 0 && custo[l - 1][c] < melhor) {
                melhor = custo[l - 1][c];
            }
            if (c > 0 && custo[l][c - 1] < melhor) {
                melhor = custo[l][c - 1];
            }
            custo[l][c] = melhor >= INF ? INF : melhor + g[l][c];
        }
    }
    printf("Bateria gasta: %d%%\n", custo[L - 1][C - 1]);
    char cam[L + C];
    int k = 0, l = L - 1, c = C - 1;
    while (l > 0 || c > 0) {
        if (c == 0 || (l > 0 && custo[l - 1][c] <= custo[l][c - 1])) {
            cam[k++] = 'B';
            l--;
        } else {
            cam[k++] = 'D';
            c--;
        }
    }
    printf("Caminho: ");
    for (int i = k - 1; i >= 0; i--) {
        printf("%c", cam[i]);
    }
    printf("\n");
    return 0;
}
