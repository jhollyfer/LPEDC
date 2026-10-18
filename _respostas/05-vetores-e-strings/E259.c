// 0044 · Matrizes
// Exercício E259 · ★☆☆

#include <stdio.h>

#define N 3

int main(void) {
    int m[N][N] = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8},
    };

    for (int l = 0; l < N; l++) {
        printf("%d %d %d\n", m[l][0], m[l][1], m[l][2]);
    }

    int principal = 0;
    int secundaria = 0;
    for (int i = 0; i < N; i++) {
        principal += m[i][i];
        secundaria += m[i][N - 1 - i];
    }
    printf("Diagonal principal: %d\n", principal);
    printf("Diagonal secundária: %d\n", secundaria);
    return 0;
}
