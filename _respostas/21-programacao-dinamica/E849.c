// 0142 · Distância de edição
// Exercício E849 · ★★☆

#include <stdio.h>
#include <string.h>

#define MAX 30

int menor(int x, int y) {
    return x < y ? x : y;
}

int maior(int x, int y) {
    return x > y ? x : y;
}

// distância só com inserir e remover (sem troca)
int dist_sem_troca(const char *a, const char *b) {
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
                d[i][j] = 1 + menor(d[i - 1][j], d[i][j - 1]); // remove ou insere
            }
        }
    }
    return d[m][n];
}

int lcs(const char *a, const char *b) {
    int m = strlen(a), n = strlen(b);
    int c[MAX + 1][MAX + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = maior(c[i - 1][j], c[i][j - 1]);
            }
        }
    }
    return c[m][n];
}

int main(void) {
    const char *pares[][2] = {
        {"PALMEIRAS", "PALMAS"},
        {"CARTA", "ARTES"},
        {"BOLO", "BOLA"},
        {"RECIFE", "FORTALEZA"},
    };
    for (int p = 0; p < 4; p++) {
        const char *a = pares[p][0], *b = pares[p][1];
        int m = strlen(a), n = strlen(b), l = lcs(a, b);
        printf("%-9s %-9s  PD: %2d   m + n - 2 x LCS = %d + %d - 2 x %d = %2d\n",
               a, b, dist_sem_troca(a, b), m, n, l, m + n - 2 * l);
    }
    return 0;
}
