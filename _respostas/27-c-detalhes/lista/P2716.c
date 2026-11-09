// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2716 · ★★☆ · A tabela de distâncias da BR

#include <stdio.h>

void preencher(int n, const int km[n], int d[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int dif = km[i] - km[j];
            d[i][j] = dif < 0 ? -dif : dif;
        }
    }
}

void mais_distantes(int n, int d[n][n], int *a, int *b) {
    *a = 0;
    *b = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (d[i][j] > d[*a][*b]) {
                *a = i;
                *b = j;
            }
        }
    }
}

int main(void) {
    int km[] = {0, 12, 30, 45};
    int n = 4;
    int d[n][n];
    preencher(n, km, d);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", d[i][j]);
        }
        printf("\n");
    }
    int a, b;
    mais_distantes(n, d, &a, &b);
    printf("mais distantes: %d e %d (%d km)\n", a, b, d[a][b]);
    return 0;
}
