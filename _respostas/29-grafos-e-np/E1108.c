// 0185 · Cadeia de matrizes
// Exercício E1108 · ★★☆

#include <limits.h>
#include <stdio.h>

#define N 5

const int p[N + 1] = {40, 5, 50, 2, 30, 8};
long mn[N + 1][N + 1], mx[N + 1][N + 1];
int sn[N + 1][N + 1], sx[N + 1][N + 1];

void mostra(int s[N + 1][N + 1], int i, int j) {
    if (i == j) {
        printf("A%d", i);
        return;
    }
    printf("(");
    mostra(s, i, s[i][j]);
    printf(" ");
    mostra(s, s[i][j] + 1, j);
    printf(")");
}

int main(void) {
    for (int tam = 2; tam <= N; tam++)
        for (int i = 1; i + tam - 1 <= N; i++) {
            int j = i + tam - 1;
            mn[i][j] = LONG_MAX;
            mx[i][j] = -1;
            for (int k = i; k < j; k++) {
                long junta = (long)p[i - 1] * p[k] * p[j];
                long a = mn[i][k] + mn[k + 1][j] + junta;
                long b = mx[i][k] + mx[k + 1][j] + junta;
                if (a < mn[i][j]) mn[i][j] = a, sn[i][j] = k;
                if (b > mx[i][j]) mx[i][j] = b, sx[i][j] = k;
            }
        }
    printf("Melhor: ");
    mostra(sn, 1, N);
    printf(" = %ld\nPior:   ", mn[1][N]);
    mostra(sx, 1, N);
    printf(" = %ld\nA pior custa %.1f vezes a melhor\n", mx[1][N], (double)mx[1][N] / mn[1][N]);
    return 0;
}
