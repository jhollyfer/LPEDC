// Lista · Módulo 21 · Programação dinâmica
// Exercício P2108 · ★☆☆ · A tabela da LCS na tela

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *a = "ARARA", *b = "ARAPUA";
    int m = (int)strlen(a), n = (int)strlen(b);
    int t[8][8];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                t[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                t[i][j] = t[i - 1][j - 1] + 1;
            } else {
                t[i][j] = t[i - 1][j] > t[i][j - 1] ? t[i - 1][j] : t[i][j - 1];
            }
        }
    }
    printf("   %3c", '-');
    for (int j = 0; j < n; j++) {
        printf("%3c", b[j]);
    }
    printf("\n");
    for (int i = 0; i <= m; i++) {
        printf("%3c", i == 0 ? '-' : a[i - 1]);
        for (int j = 0; j <= n; j++) {
            printf("%3d", t[i][j]);
        }
        printf("\n");
    }
    printf("LCS de %s e %s: %d letras\n", a, b, t[m][n]);
    return 0;
}
