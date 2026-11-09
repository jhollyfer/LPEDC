// Lista · Módulo 21 · Programação dinâmica
// Exercício P2127 · ★★★ · A distância que erra por uma letra

#include <stdio.h>
#include <string.h>

int min3(int x, int y, int z) {
    int m = x < y ? x : y;
    return m < z ? m : z;
}

int edicao(const char *a, const char *b) {
    int m = (int)strlen(a), n = (int)strlen(b);
    int d[16][16];
    for (int i = 0; i <= m; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        d[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int troca = a[i - 1] == b[j - 1] ? 0 : 1;
            d[i][j] = min3(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + troca);
        }
    }
    return d[m][n];
}

int main(void) {
    const char *pares[4][2] = {{"CAVALO", "CAVALO"}, {"CAVALO", "CABELO"}, {"MANAUS", "MANAUARA"}, {"TUCANO", "TUCUMA"}};
    for (int k = 0; k < 4; k++) {
        printf("%s -> %s: %d\n", pares[k][0], pares[k][1], edicao(pares[k][0], pares[k][1]));
    }
    return 0;
}
