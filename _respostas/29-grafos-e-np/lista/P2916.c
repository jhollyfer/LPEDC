// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2916 · ★★☆ · Tabela de cortes e parênteses

#include <limits.h>
#include <stdio.h>

#define N 6

const int p[N + 1] = {20, 40, 10, 6, 15, 30, 12};
long m[N + 1][N + 1];
int s[N + 1][N + 1];

void mostra(int i, int j) {
    if (i == j) {
        printf("A%d", i);
        return;
    }
    printf("(");
    mostra(i, s[i][j]);
    printf(" ");
    mostra(s[i][j] + 1, j);
    printf(")");
}

int main(void) {
    for (int t = 2; t <= N; t++)
        for (int i = 1; i + t - 1 <= N; i++) {
            int j = i + t - 1;
            m[i][j] = LONG_MAX;
            for (int k = i; k < j; k++) {
                long c = m[i][k] + m[k + 1][j] + (long)p[i - 1] * p[k] * p[j];
                if (c < m[i][j]) m[i][j] = c, s[i][j] = k;
            }
        }
    printf("Tabela s:\n");
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (j <= i) printf("%3s", "-");
            else printf("%3d", s[i][j]);
        }
        printf("\n");
    }
    printf("Custo mínimo: %ld\nOrdem: ", m[1][N]);
    mostra(1, N);
    printf("\n");
    return 0;
}
