// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2926 · ★★★ · De ciclo hamiltoniano para caixeiro viajante

#include <stdio.h>

#define N 6
#define INF 1000000

int d[N][N], dp[1 << N][N];

int held_karp(void) {
    for (int s = 0; s < (1 << N); s++)
        for (int j = 0; j < N; j++) dp[s][j] = INF;
    dp[1][0] = 0;
    for (int s = 1; s < (1 << N); s += 2)
        for (int j = 0; j < N; j++) {
            if (!(s >> j & 1) || dp[s][j] == INF) continue;
            for (int k = 1; k < N; k++)
                if (!(s >> k & 1) && dp[s][j] + d[j][k] < dp[s | 1 << k][k])
                    dp[s | 1 << k][k] = dp[s][j] + d[j][k];
        }
    int melhor = INF;
    for (int j = 1; j < N; j++)
        if (dp[(1 << N) - 1][j] + d[j][0] < melhor) melhor = dp[(1 << N) - 1][j] + d[j][0];
    return melhor;
}

void decide(const char *nome, int ne, int a[][2]) {
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++) d[x][y] = x == y ? 0 : 2;
    for (int k = 0; k < ne; k++) d[a[k][0]][a[k][1]] = d[a[k][1]][a[k][0]] = 1;
    int c = held_karp();
    printf("%s: volta mais barata = %d -> %s\n", nome, c, c == N ? "tem ciclo hamiltoniano" : "não tem");
}

int main(void) {
    int g1[][2] = {{0, 1}, {0, 2}, {0, 4}, {1, 2}, {1, 3}, {2, 3}, {3, 4}, {3, 5}, {4, 5}};
    int g2[][2] = {{0, 1}, {1, 2}, {2, 0}, {0, 3}, {3, 4}, {4, 0}, {0, 5}, {5, 1}};
    decide("G1", 9, g1);
    decide("G2", 8, g2);
    return 0;
}
