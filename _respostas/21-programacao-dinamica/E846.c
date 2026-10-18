// 0141 · Maior subsequência comum (LCS)
// Exercício E846 · ★★★

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int compara(const void *x, const void *y) {
    int a = *(const int *) x, b = *(const int *) y;
    return (a > b) - (a < b);
}

int lcs_vetor(const int a[], int m, const int b[], int n, int saida[]) {
    int c[MAX + 1][MAX + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
            } else {
                c[i][j] = c[i][j - 1];
            }
        }
    }
    int k = c[m][n], i = m, j = n;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            saida[--k] = a[i - 1];
            i--;
            j--;
        } else if (c[i - 1][j] >= c[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    return c[m][n];
}

int main(void) {
    int preco[] = {31, 28, 35, 30, 33, 29, 36, 40, 34, 38, 41, 37, 33};
    int n = 13;

    // cópia ordenada e SEM repetidos: só sequências que sobem de verdade
    int ord[MAX];
    for (int i = 0; i < n; i++) {
        ord[i] = preco[i];
    }
    qsort(ord, n, sizeof ord[0], compara);
    int u = 0;
    for (int i = 0; i < n; i++) {
        if (u == 0 || ord[i] != ord[u - 1]) {
            ord[u++] = ord[i];
        }
    }

    int sobe[MAX];
    int t = lcs_vetor(preco, n, ord, u, sobe);
    printf("Maior sequência de altas: %d dias\n", t);
    printf("Preços:");
    for (int k = 0; k < t; k++) {
        printf(" %d", sobe[k]);
    }
    printf("\n");
    return 0;
}
