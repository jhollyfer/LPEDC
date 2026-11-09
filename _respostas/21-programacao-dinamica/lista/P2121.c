// Lista · Módulo 21 · Programação dinâmica
// Exercício P2121 · ★★★ · A ordem das multiplicações de matrizes

#include <stdio.h>

#define N 5

const long d[N + 1] = {30, 35, 15, 5, 10, 20};
long m[N + 1][N + 1];
int s[N + 1][N + 1];

void mostra(int i, int j) {
    if (i == j) {
        printf("A%d", i);
        return;
    }
    printf("(");
    mostra(i, s[i][j]);
    mostra(s[i][j] + 1, j);
    printf(")");
}

int main(void) {
    for (int i = 1; i <= N; i++) {
        m[i][i] = 0;
    }
    for (int tam = 2; tam <= N; tam++) {
        for (int i = 1; i + tam - 1 <= N; i++) {
            int j = i + tam - 1;
            m[i][j] = -1;
            for (int k = i; k < j; k++) {
                long c = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (m[i][j] < 0 || c < m[i][j]) {
                    m[i][j] = c;
                    s[i][j] = k;
                }
            }
        }
    }
    long esq = 0, linhas = d[0];
    for (int k = 1; k < N; k++) {
        esq += linhas * d[k] * d[k + 1];
    }
    printf("Ótimo: %ld multiplicações com ", m[1][N]);
    mostra(1, N);
    printf("\n");
    printf("Da esquerda para a direita: %ld multiplicações\n", esq);
    return 0;
}
