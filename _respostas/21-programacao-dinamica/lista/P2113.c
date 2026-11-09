// Lista · Módulo 21 · Programação dinâmica
// Exercício P2113 · ★★☆ · LCS de três versões

#include <stdio.h>
#include <string.h>

int max3(int x, int y, int z) {
    int m = x > y ? x : y;
    return m > z ? m : z;
}

int main(void) {
    const char *a = "AMAZONIA", *b = "AMAZONAS", *c = "MAZOMBA";
    int m = (int)strlen(a), n = (int)strlen(b), p = (int)strlen(c);
    int t[9][9][9];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= p; k++) {
                if (i == 0 || j == 0 || k == 0) {
                    t[i][j][k] = 0;
                } else if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
                    t[i][j][k] = 1 + t[i - 1][j - 1][k - 1];
                } else {
                    t[i][j][k] = max3(t[i - 1][j][k], t[i][j - 1][k], t[i][j][k - 1]);
                }
            }
        }
    }
    int tam = t[m][n][p];
    char r[16];
    r[tam] = '\0';
    int i = m, j = n, k = p, pos = tam;
    while (i > 0 && j > 0 && k > 0) {
        if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
            r[--pos] = a[i - 1];
            i--;
            j--;
            k--;
        } else if (t[i - 1][j][k] == t[i][j][k]) {
            i--;
        } else if (t[i][j - 1][k] == t[i][j][k]) {
            j--;
        } else {
            k--;
        }
    }
    printf("Comum às três: %s (%d letras)\n", r, tam);
    return 0;
}
