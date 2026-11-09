// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1909 · ★☆☆ · Rainhas de 1 a 9

#include <stdbool.h>
#include <stdio.h>

#define MAX 9

bool col_ocup[MAX], d1[2 * MAX], d2[2 * MAX];
long solucoes;

void coloca(int lin, int n) {
    if (lin == n) {
        solucoes++;
        return;
    }
    for (int col = 0; col < n; col++) {
        int a = lin - col + n - 1, b = lin + col;
        if (col_ocup[col] || d1[a] || d2[b]) {
            continue;
        }
        col_ocup[col] = d1[a] = d2[b] = true;
        coloca(lin + 1, n);
        col_ocup[col] = d1[a] = d2[b] = false;
    }
}

int main(void) {
    printf(" N  soluções\n");
    for (int n = 1; n <= MAX; n++) {
        solucoes = 0;
        coloca(0, n);
        printf("%2d  %ld\n", n, solucoes);
    }
    return 0;
}
