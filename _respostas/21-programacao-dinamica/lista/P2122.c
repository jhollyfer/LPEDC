// Lista · Módulo 21 · Programação dinâmica
// Exercício P2122 · ★★★ · Todas as maiores subsequências comuns

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXR 32

const char *a = "ABCBDAB", *b = "BDCABA";
int t[16][16];
char achadas[MAXR][8];
int na = 0;

void gera(int i, int j, char buf[], int pos) {
    if (pos == 0 || i == 0 || j == 0) {
        for (int k = 0; k < na; k++) {
            if (strcmp(achadas[k], buf + pos) == 0) {
                return;
            }
        }
        if (na < MAXR) {
            strcpy(achadas[na++], buf + pos);
        }
        return;
    }
    if (a[i - 1] == b[j - 1]) {
        buf[pos - 1] = a[i - 1];
        gera(i - 1, j - 1, buf, pos - 1);
        return;
    }
    if (t[i - 1][j] == t[i][j]) {
        gera(i - 1, j, buf, pos);
    }
    if (t[i][j - 1] == t[i][j]) {
        gera(i, j - 1, buf, pos);
    }
}

int compara(const void *x, const void *y) {
    return strcmp(x, y);
}

int main(void) {
    int m = (int)strlen(a), n = (int)strlen(b);
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
    int tam = t[m][n];
    char buf[8];
    buf[tam] = '\0';
    gera(m, n, buf, tam);
    qsort(achadas, (size_t)na, sizeof achadas[0], compara);
    printf("LCS de %s e %s: tamanho %d\n", a, b, tam);
    for (int k = 0; k < na; k++) {
        printf("  %s\n", achadas[k]);
    }
    printf("%d sequências diferentes\n", na);
    return 0;
}
