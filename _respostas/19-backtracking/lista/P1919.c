// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1919 · ★★☆ · Rainhas no tabuleiro furado

#include <stdbool.h>
#include <stdio.h>

#define N 6

const char tab[N][N + 1] = {
    "......",
    "...X..",
    "......",
    "X.....",
    "......",
    "..X...",
};
bool col_ocup[N], d1[2 * N], d2[2 * N];
int pos[N];
int solucoes = 0;

void coloca(int lin) {
    if (lin == N) {
        solucoes++;
        printf("pos =");
        for (int i = 0; i < N; i++) {
            printf(" %d", pos[i]);
        }
        printf("\n");
        return;
    }
    for (int col = 0; col < N; col++) {
        int a = lin - col + N - 1, b = lin + col;
        if (col_ocup[col] || d1[a] || d2[b]) {
            continue;
        }
        if (tab[lin][col] == 'X') {
            continue;
        }
        pos[lin] = col;
        col_ocup[col] = d1[a] = d2[b] = true;
        coloca(lin + 1);
        col_ocup[col] = d1[a] = d2[b] = false;
    }
}

int main(void) {
    coloca(0);
    printf("Soluções: %d\n", solucoes);
    return 0;
}
