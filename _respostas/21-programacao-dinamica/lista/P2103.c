// Lista · Módulo 21 · Programação dinâmica
// Exercício P2103 · ★☆☆ · O carteiro e as ruas em obra

#include <stdio.h>

#define L 5
#define C 6

const char mapa[L][C + 1] = {
    "......",
    ".X..X.",
    "...X..",
    "X.....",
    "..X...",
};

int main(void) {
    long cam[L][C];
    for (int l = 0; l < L; l++) {
        for (int c = 0; c < C; c++) {
            if (mapa[l][c] == 'X') {
                cam[l][c] = 0;
            } else if (l == 0 && c == 0) {
                cam[l][c] = 1;
            } else {
                cam[l][c] = 0;
                if (l > 0) {
                    cam[l][c] += cam[l - 1][c];
                }
                if (c > 0) {
                    cam[l][c] += cam[l][c - 1];
                }
            }
        }
    }
    for (int l = 0; l < L; l++) {
        for (int c = 0; c < C; c++) {
            printf("%4ld", cam[l][c]);
        }
        printf("\n");
    }
    printf("Caminhos: %ld\n", cam[L - 1][C - 1]);
    return 0;
}
