// 0128 · N-rainhas
// Exercício E765 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define N 8

int pos[N];
int primeira[N];
bool coluna[N];
bool diag1[2 * N - 1];
bool diag2[2 * N - 1];
int solucoes = 0;

void marca(int l, int c, bool valor) {
    coluna[c] = diag1[l + c] = diag2[l - c + N - 1] = valor;
}

void rainha(int l) {
    if (l == N) {
        solucoes++;
        if (solucoes == 1) {
            for (int k = 0; k < N; k++) {
                primeira[k] = pos[k];
            }
        }
        return;
    }
    for (int c = 0; c < N; c++) {
        if (coluna[c] || diag1[l + c] || diag2[l - c + N - 1]) {
            continue;
        }
        pos[l] = c;
        marca(l, c, true);
        rainha(l + 1);
        marca(l, c, false);
    }
}

int main(void) {
    pos[0] = 3;          // a rainha colada
    marca(0, 3, true);
    rainha(1);
    printf("primeira:");
    for (int k = 0; k < N; k++) {
        printf(" %d", primeira[k]);
    }
    printf("\n%d soluções com a rainha em (0, 3)\n", solucoes);
    return 0;
}
