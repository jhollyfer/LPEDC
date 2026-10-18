// 0141 · Maior subsequência comum (LCS)
// Exercício E841 · ★☆☆

#include <stdio.h>
#include <string.h>

#define MAX 50

int lcs(const char *a, const char *b) {
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
    return c[m][n];
}

int main(void) {
    const char *pares[][2] = {
        {"ABCDEFGH", "BDCEGAH"},
        {"CASA", "ASA"},
        {"", "ABC"},
        {"XYZ", "XYZ"},
        {"ABC", "DEF"},
    };
    for (int p = 0; p < 5; p++) {
        printf("\"%s\" x \"%s\": %d\n", pares[p][0], pares[p][1], lcs(pares[p][0], pares[p][1]));
    }
    return 0;
}
