// 0142 · Distância de edição
// Exercício E850 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int tabelas = 0; // quantas tabelas foram montadas de verdade

int menor3(int x, int y, int z) {
    int m = x < y ? x : y;
    return m < z ? m : z;
}

int distancia(const char *a, const char *b) {
    int m = strlen(a), n = strlen(b);
    int d[MAX + 1][MAX + 1];
    tabelas++;
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
    const char *cadastro[] = {"BRA2E19", "RIO1A23", "SPX9F87", "BRA2E79",
                              "MGA4B56", "BRZ2E19", "PE1234", "AM12B3456"};
    int nc = 8;
    const char *lidas[] = {"BRA2E19", "RI01A23", "SPX9F8", "XYZ0000"};

    for (int k = 0; k < 4; k++) {
        printf("%s:", lidas[k]);
        int achou = 0;
        for (int p = 0; p < nc; p++) {
            // tamanhos muito diferentes: a distância é pelo menos a diferença
            if (abs((int) strlen(lidas[k]) - (int) strlen(cadastro[p])) > 1) {
                continue;
            }
            int d = distancia(lidas[k], cadastro[p]);
            if (d <= 1) {
                printf(" %s (%d)", cadastro[p], d);
                achou = 1;
            }
        }
        printf("%s\n", achou ? "" : " nenhuma");
    }
    printf("tabelas montadas: %d de %d\n", tabelas, 4 * nc);
    return 0;
}
