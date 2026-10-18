// 0128 · N-rainhas
// Exercício E764 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define N 6

int pos[N];
bool coluna[N];
bool diag1[2 * N - 1];
bool diag2[2 * N - 1];
int solucoes = 0;

void rainha(int l) {
    if (l == N) {
        solucoes++;
        for (int k = 0; k < N; k++) {
            printf(k == 0 ? "%d" : " %d", pos[k]);
        }
        printf("\n");
        return;
    }
    for (int c = 0; c < N; c++) {
        if (coluna[c] || diag1[l + c] || diag2[l - c + N - 1]) {
            continue;
        }
        pos[l] = c;
        coluna[c] = diag1[l + c] = diag2[l - c + N - 1] = true;
        rainha(l + 1);
        coluna[c] = diag1[l + c] = diag2[l - c + N - 1] = false;
    }
}

int main(void) {
    rainha(0);
    printf("%d soluções\n", solucoes);
    return 0;
}
