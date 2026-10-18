// 0128 · N-rainhas
// Exercício E766 · ★★☆

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int n;
int pos[MAX];
int primeira[MAX];
bool coluna[MAX];
int solucoes;

void senta(int l) {
    if (l == n) {
        solucoes++;
        if (solucoes == 1) {
            for (int k = 0; k < n; k++) {
                primeira[k] = pos[k];
            }
        }
        return;
    }
    for (int c = 0; c < n; c++) {
        if (coluna[c] || (l > 0 && abs(c - pos[l - 1]) == 1)) {
            continue;   // coluna ocupada, ou vizinho da fileira de cima
        }
        pos[l] = c;
        coluna[c] = true;
        senta(l + 1);
        coluna[c] = false;
    }
}

int main(void) {
    for (n = 4; n <= 6; n++) {
        solucoes = 0;
        senta(0);
        printf("n = %d: %d arrumações, primeira:", n, solucoes);
        for (int k = 0; k < n; k++) {
            printf(" %d", primeira[k]);
        }
        printf("\n");
    }
    return 0;
}
