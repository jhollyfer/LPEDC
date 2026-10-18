// 0142 · Distância de edição
// Exercício E847 · ★☆☆

#include <stdio.h>
#include <string.h>

#define MAX 30

int menor3(int x, int y, int z) {
    int m = x < y ? x : y;
    return m < z ? m : z;
}

int distancia(const char *a, const char *b) {
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
    return d[m][n];
}

int main(void) {
    const char *pares[][2] = {
        {"LIVRO", "LIBRA"},
        {"", "SOL"},
        {"CASA", "CASA"},
        {"ABACAXI", "ABACATE"},
        {"FUTEBOL", "BASQUETE"},
    };
    for (int p = 0; p < 5; p++) {
        printf("\"%s\" -> \"%s\": %d\n", pares[p][0], pares[p][1],
               distancia(pares[p][0], pares[p][1]));
    }
    return 0;
}
