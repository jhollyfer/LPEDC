// 0141 · Maior subsequência comum (LCS)
// Exercício E845 · ★★★
//
// Resposta: a comparação era a[i] == b[j]. A linha i fala do prefixo
// a[0..i-1], cuja última letra é a[i - 1]; a[i] é a letra SEGUINTE. Com o
// erro, a tabela calcula a LCS de a + 1 e b + 1 (perdendo as primeiras
// letras) e, na última célula, compara '\0' com '\0', que sempre bate e
// soma 1. Conserto: a[i - 1] == b[j - 1].

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
    const char *base = "AMOR";
    const char *anagrama[] = {"ROMA", "MORA", "RAMO", "OMAR", "AMOR"};
    for (int k = 0; k < 5; k++) {
        printf("%s x %s: %d\n", base, anagrama[k], lcs(base, anagrama[k]));
    }
    return 0;
}
