// 0189 · Juntando tudo
// Exercício E1129 · ★☆☆

#include <stdio.h>
#include <stdlib.h>

#define N 5

const char *pontos[N] = {"Padaria", "Escola", "Posto", "Banco", "Feira"};
const int px[N] = {0, 3, 5, 1, 4};
const int py[N] = {0, 2, 5, 4, 0};
int d[N][N];

int custo(const int r[]) {
    int c = 0;
    for (int i = 0; i < N; i++) c += d[r[i]][r[(i + 1) % N]];
    return c;
}

int main(void) {
    for (int a = 0; a < N; a++)
        for (int b = 0; b < N; b++) d[a][b] = abs(px[a] - px[b]) + abs(py[a] - py[b]);
    printf("%8s", "");
    for (int b = 0; b < N; b++) printf("%8s", pontos[b]);
    printf("\n");
    for (int a = 0; a < N; a++) {
        printf("%-8s", pontos[a]);
        for (int b = 0; b < N; b++) printf("%8d", d[a][b]);
        printf("\n");
    }
    int r1[N] = {0, 1, 2, 3, 4}, r2[N] = {0, 4, 1, 2, 3};
    printf("Rota 1: %d quarteirões\n", custo(r1));
    printf("Rota 2: %d quarteirões\n", custo(r2));
    return 0;
}
