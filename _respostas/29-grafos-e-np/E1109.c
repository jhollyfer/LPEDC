// 0185 · Cadeia de matrizes
// Exercício E1109 · ★★★

#include <limits.h>
#include <stdio.h>

#define N 4

const int p[N + 1] = {10, 30, 5, 60, 10};
long m[N + 1][N + 1];
int s[N + 1][N + 1];

int main(void) {
    for (int i = N; i >= 1; i--) {         // de baixo para cima: a linha i usa as de baixo
        for (int j = i + 1; j <= N; j++) { // e, na linha, m[i][k] com k < j já está pronto
            m[i][j] = LONG_MAX;
            for (int k = i; k < j; k++) {
                long custo = m[i][k] + m[k + 1][j] + (long)p[i - 1] * p[k] * p[j];
                if (custo < m[i][j]) {
                    m[i][j] = custo;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("m[1][3] = %ld\n", m[1][3]);
    printf("m[1][4] = %ld (corte em k = %d)\n", m[1][4], s[1][4]);
    return 0;
}
