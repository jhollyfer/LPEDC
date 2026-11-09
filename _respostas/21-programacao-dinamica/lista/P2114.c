// Lista · Módulo 21 · Programação dinâmica
// Exercício P2114 · ★★☆ · Edição com troca mais cara

#include <stdio.h>
#include <string.h>

int min3(int x, int y, int z) {
    int m = x < y ? x : y;
    return m < z ? m : z;
}

int edicao(const char *a, const char *b, int insere, int remove, int troca) {
    int m = (int)strlen(a), n = (int)strlen(b);
    int d[16][16];
    for (int i = 0; i <= m; i++) {
        d[i][0] = i * remove;
    }
    for (int j = 0; j <= n; j++) {
        d[0][j] = j * insere;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int diag = d[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 0 : troca);
            d[i][j] = min3(d[i - 1][j] + remove, d[i][j - 1] + insere, diag);
        }
    }
    return d[m][n];
}

int main(void) {
    const char *pares[4][2] = {{"CASA", "COISA"}, {"GATO", "PATO"}, {"BOLA", "LOBA"}, {"FEIRA", "FERIADO"}};
    for (int k = 0; k < 4; k++) {
        printf("%s -> %s: comum %d, troca cara %d\n", pares[k][0], pares[k][1],
               edicao(pares[k][0], pares[k][1], 1, 1, 1), edicao(pares[k][0], pares[k][1], 1, 1, 2));
    }
    return 0;
}
