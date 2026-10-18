// 0141 · Maior subsequência comum (LCS)
// Exercício E844 · ★★☆

#include <stdio.h>
#include <string.h>

#define MAX 50

// 1 se p é subsequência de t: anda em t e avança em p quando a letra bate
int eh_subsequencia(const char *p, const char *t) {
    while (*p != '\0' && *t != '\0') {
        if (*p == *t) {
            p++;
        }
        t++;
    }
    return *p == '\0';
}

int main(void) {
    const char *a = "BANANA";
    const char *b = "CABANA";
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

    // a menor supersequência comum: as letras da LCS aparecem uma vez só,
    // e todas as outras letras das duas entram também
    char sup[2 * MAX + 1];
    int k = m + n - c[m][n];
    sup[k] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            sup[--k] = a[i - 1]; // comum: entra uma vez
            i--;
            j--;
        } else if (c[i - 1][j] >= c[i][j - 1]) {
            sup[--k] = a[i - 1]; // a letra de a não está na LCS: entra sozinha
            i--;
        } else {
            sup[--k] = b[j - 1]; // a letra de b não está na LCS: entra sozinha
            j--;
        }
    }
    while (i > 0) {
        sup[--k] = a[--i]; // sobrou começo de a
    }
    while (j > 0) {
        sup[--k] = b[--j]; // sobrou começo de b
    }

    printf("LCS: %d letras\n", c[m][n]);
    printf("Supersequência: %s (%d letras)\n", sup, m + n - c[m][n]);
    printf("%s está nela? %s\n", a, eh_subsequencia(a, sup) ? "sim" : "não");
    printf("%s está nela? %s\n", b, eh_subsequencia(b, sup) ? "sim" : "não");
    return 0;
}
