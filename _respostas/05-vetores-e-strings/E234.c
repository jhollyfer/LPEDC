// 0039 · Matrizes
// Exercício E234 · ★★★

#include <stdio.h>

#define LINHAS 4
#define COLUNAS 5

int vizinhas(int campo[][COLUNAS], int l, int c) {
    int bombas = 0;
    for (int i = l - 1; i <= l + 1; i++) {
        for (int j = c - 1; j <= c + 1; j++) {
            if (i >= 0 && i < LINHAS && j >= 0 && j < COLUNAS) {
                bombas += campo[i][j];
            }
        }
    }
    return bombas;
}

int main(void) {
    int campo[LINHAS][COLUNAS] = {
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1},
    };

    for (int l = 0; l < LINHAS; l++) {
        for (int c = 0; c < COLUNAS; c++) {
            if (c > 0) {
                printf(" ");
            }
            if (campo[l][c] == 1) {
                printf("*");
            } else {
                printf("%d", vizinhas(campo, l, c));
            }
        }
        printf("\n");
    }
    return 0;
}
