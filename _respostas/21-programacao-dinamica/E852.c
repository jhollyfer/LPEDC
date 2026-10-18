// 0142 · Distância de edição
// Exercício E852 · ★★★

#include <stdio.h>
#include <string.h>

#define MAX 30

int menor3(int x, int y, int z) {
    int m = x < y ? x : y;
    return m < z ? m : z;
}

void alinha(const char *a, const char *b) {
    int m = strlen(a), n = strlen(b);
    int d[MAX + 1][MAX + 1];
    for (int i = 0; i <= m; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        d[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = 1 + menor3(d[i - 1][j - 1], d[i - 1][j], d[i][j - 1]);
            }
        }
    }

    // as três linhas do alinhamento, montadas de trás para a frente
    char cima[2 * MAX], baixo[2 * MAX], marca[2 * MAX];
    int k = 0, i = m, j = n;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && a[i - 1] == b[j - 1]) {
            cima[k] = a[i - 1];
            baixo[k] = b[j - 1];
            marca[k] = '=';
            i--;
            j--;
        } else if (i > 0 && j > 0 && d[i][j] == d[i - 1][j - 1] + 1) {
            cima[k] = a[i - 1];
            baixo[k] = b[j - 1];
            marca[k] = 'T';
            i--;
            j--;
        } else if (i > 0 && d[i][j] == d[i - 1][j] + 1) {
            cima[k] = a[i - 1];
            baixo[k] = '-';
            marca[k] = 'R';
            i--;
        } else {
            cima[k] = '-';
            baixo[k] = b[j - 1];
            marca[k] = 'I';
            j--;
        }
        k++;
    }

    printf("%s -> %s: distância %d\n", a, b, d[m][n]);
    for (int t = k - 1; t >= 0; t--) {
        printf(" %c", cima[t]);
    }
    printf("\n");
    for (int t = k - 1; t >= 0; t--) {
        printf(" %c", baixo[t]);
    }
    printf("\n");
    for (int t = k - 1; t >= 0; t--) {
        printf(" %c", marca[t]);
    }
    printf("\n");
}

int main(void) {
    alinha("SABADO", "SALDO");
    alinha("ESTRELA", "ESTERIL");
    return 0;
}
