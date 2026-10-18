// 0141 · Maior subsequência comum (LCS)
// Exercício E843 · ★★☆

#include <stdio.h>

#define MAX 20

// LCS de dois vetores de int; grava a subsequência em saida e devolve o tamanho
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
    int ana[] = {12, 7, 33, 5, 21, 8, 40, 17};
    int beto[] = {7, 5, 9, 21, 40, 3, 17, 12};
    int comum[MAX];

    int t = lcs_vetor(ana, 8, beto, 8, comum);
    printf("%d músicas em comum, na mesma ordem:", t);
    for (int k = 0; k < t; k++) {
        printf(" %d", comum[k]);
    }
    printf("\n");
    return 0;
}
