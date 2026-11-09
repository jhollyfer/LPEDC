// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1920 · ★★☆ · O rodízio dos quatro feirantes

#include <stdbool.h>
#include <stdio.h>

#define N 4

int g[N][N];
bool na_lin[N][N + 1], na_col[N][N + 1];
int total = 0, primeiro_dia = 0;

void preenche(int k) {
    if (k == N * N) {
        total++;
        if (total == 1) {
            for (int l = 0; l < N; l++) {
                printf("%d %d %d %d\n", g[l][0], g[l][1], g[l][2], g[l][3]);
            }
        }
        if (g[0][0] == 1 && g[0][1] == 2 && g[0][2] == 3 && g[0][3] == 4) {
            primeiro_dia++;
        }
        return;
    }
    int l = k / N, c = k % N;
    for (int x = 1; x <= N; x++) {
        if (na_lin[l][x] || na_col[c][x]) {
            continue;
        }
        g[l][c] = x;
        na_lin[l][x] = na_col[c][x] = true;
        preenche(k + 1);
        na_lin[l][x] = na_col[c][x] = false;
    }
}

int main(void) {
    preenche(0);
    printf("Escalas: %d\n", total);
    printf("Com o primeiro dia 1 2 3 4: %d\n", primeiro_dia);
    return 0;
}
