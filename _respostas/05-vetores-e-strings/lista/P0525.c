// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0525 · ★★★ · A ronda em espiral

#include <stdio.h>

#define L 4
#define C 5

int main(void) {
    int g[L][C] = {{ 1,  2,  3,  4,  5},
                   { 6,  7,  8,  9, 10},
                   {11, 12, 13, 14, 15},
                   {16, 17, 18, 19, 20}};
    int passo[L][C];
    int cima = 0, baixo = L - 1, esq = 0, dir = C - 1;
    int p = 1;

    printf("Ronda:");
    while (cima <= baixo && esq <= dir) {
        for (int j = esq; j <= dir; j++) {
            printf(" %d", g[cima][j]);
            passo[cima][j] = p++;
        }
        cima++;
        for (int i = cima; i <= baixo; i++) {
            printf(" %d", g[i][dir]);
            passo[i][dir] = p++;
        }
        dir--;
        if (cima <= baixo) {
            for (int j = dir; j >= esq; j--) {
                printf(" %d", g[baixo][j]);
                passo[baixo][j] = p++;
            }
            baixo--;
        }
        if (esq <= dir) {
            for (int i = baixo; i >= cima; i--) {
                printf(" %d", g[i][esq]);
                passo[i][esq] = p++;
            }
            esq++;
        }
    }
    printf("\n");

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            printf("%3d", passo[i][j]);
        }
        printf("\n");
    }
    return 0;
}
