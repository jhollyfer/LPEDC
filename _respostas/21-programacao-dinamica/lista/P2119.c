// Lista · Módulo 21 · Programação dinâmica
// Exercício P2119 · ★★☆ · O triângulo do cofrinho

#include <stdio.h>

#define N 6

int main(void) {
    const int t[N][N] = {
        {7},
        {3, 8},
        {8, 1, 0},
        {2, 7, 4, 4},
        {4, 5, 2, 6, 5},
        {1, 6, 9, 3, 2, 8},
    };
    int melhor[N][N];
    for (int c = 0; c < N; c++) {
        melhor[N - 1][c] = t[N - 1][c];
    }
    for (int l = N - 2; l >= 0; l--) {
        for (int c = 0; c <= l; c++) {
            int a = melhor[l + 1][c], b = melhor[l + 1][c + 1];
            melhor[l][c] = t[l][c] + (a > b ? a : b);
        }
    }
    printf("Maior total: R$ %d\n", melhor[0][0]);
    printf("Caminho:");
    for (int l = 0, c = 0; l < N; l++) {
        printf(" %d", t[l][c]);
        if (l + 1 < N && melhor[l + 1][c + 1] > melhor[l + 1][c]) {
            c++;
        }
    }
    printf("\n");
    return 0;
}
