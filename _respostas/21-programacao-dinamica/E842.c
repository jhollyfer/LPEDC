// 0141 · Maior subsequência comum (LCS)
// Exercício E842 · ★☆☆

#include <stdio.h>
#include <string.h>

#define MAX 50

int main(void) {
    const char *a = "PROGRAMAR";
    const char *b = "PAGAR";
    int m = strlen(a), n = strlen(b);
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
    printf("Tamanho da LCS: %d\n", c[m][n]);

    char lcs[MAX + 1];
    int k = c[m][n];
    lcs[k] = '\0';
    int i = m, j = n, passos = 0;
    while (i > 0 && j > 0) {
        passos++;
        if (a[i - 1] == b[j - 1]) {
            lcs[--k] = a[i - 1];
            i--;
            j--;
        } else if (c[i - 1][j] >= c[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    printf("LCS: %s\n", lcs);
    printf("Passos na volta: %d\n", passos);
    return 0;
}
