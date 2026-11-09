// 0185 · Cadeia de matrizes
// Exercício E1110 · ★★★

#include <limits.h>
#include <stdio.h>

#define N 5

const int p0[N + 1] = {10, 20, 5, 40, 30, 2};

long guloso(void) {
    int p[N + 1], n = N + 1; // n = quantos números de dimensão ainda restam
    for (int i = 0; i <= N; i++) p[i] = p0[i];
    long total = 0;
    while (n > 2) {
        int melhor = 1;
        for (int i = 2; i < n - 1; i++)
            if ((long)p[i - 1] * p[i] * p[i + 1] < (long)p[melhor - 1] * p[melhor] * p[melhor + 1]) melhor = i;
        long c = (long)p[melhor - 1] * p[melhor] * p[melhor + 1];
        printf("  junta %dx%d com %dx%d: %ld\n", p[melhor - 1], p[melhor], p[melhor], p[melhor + 1], c);
        total += c;
        for (int i = melhor; i < n - 1; i++) p[i] = p[i + 1]; // a dimensão do meio some
        n--;
    }
    return total;
}

long otimo(void) {
    long m[N + 1][N + 1] = {{0}};
    for (int tam = 2; tam <= N; tam++)
        for (int i = 1; i + tam - 1 <= N; i++) {
            int j = i + tam - 1;
            m[i][j] = LONG_MAX;
            for (int k = i; k < j; k++) {
                long c = m[i][k] + m[k + 1][j] + (long)p0[i - 1] * p0[k] * p0[j];
                if (c < m[i][j]) m[i][j] = c;
            }
        }
    return m[1][N];
}

int main(void) {
    printf("Guloso (junta o par vizinho mais barato):\n");
    long g = guloso();
    long o = otimo();
    printf("Guloso: %ld\nPD: %ld\n", g, o);
    return 0;
}
