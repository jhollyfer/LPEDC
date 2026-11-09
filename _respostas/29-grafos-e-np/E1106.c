// 0185 · Cadeia de matrizes
// Exercício E1106 · ★☆☆

#include <limits.h>
#include <stdio.h>

#define N 5

const int p[N + 1] = {8, 20, 4, 15, 6, 25};
long m[N + 1][N + 1];
int s[N + 1][N + 1];
int contador = 0; // numera as matrizes intermediárias M1, M2, ...

// faz Ai..Aj na ordem ótima; devolve o número da intermediária (0 = a própria Ai)
int executa(int i, int j) {
    if (i == j) return 0;
    int k = s[i][j];
    int esq = executa(i, k), dir = executa(k + 1, j);
    int eu = ++contador;
    printf("M%d = ", eu);
    if (esq) printf("M%d", esq); else printf("A%d", i);
    printf(" x ");
    if (dir) printf("M%d", dir); else printf("A%d", j);
    printf("  (%dx%d por %dx%d: %ld)\n", p[i - 1], p[k], p[k], p[j], (long)p[i - 1] * p[k] * p[j]);
    return eu;
}

int main(void) {
    for (int tam = 2; tam <= N; tam++)
        for (int i = 1; i + tam - 1 <= N; i++) {
            int j = i + tam - 1;
            m[i][j] = LONG_MAX;
            for (int k = i; k < j; k++) {
                long c = m[i][k] + m[k + 1][j] + (long)p[i - 1] * p[k] * p[j];
                if (c < m[i][j]) m[i][j] = c, s[i][j] = k;
            }
        }
    executa(1, N);
    printf("Total: %ld\n", m[1][N]);
    return 0;
}
