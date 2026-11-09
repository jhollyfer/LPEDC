// 0189 · Juntando tudo
// Exercício E1134 · ★★★

#include <stdio.h>
#include <stdlib.h>

#define N 8
#define INF 1000000000

const char *pontos[N] = {"Farmácia", "Ana", "Bruno", "Clara", "Dênis", "Edna", "Fábio", "Gil"};
const int px[N] = {0, 1, 4, 6, 7, 5, 2, 3};
const int py[N] = {0, 3, 4, 3, 0, 1, 6, 1};
int d[N][N];
int dp[1 << N][N];

int main(void) {
    for (int a = 0; a < N; a++)
        for (int b = 0; b < N; b++) d[a][b] = abs(px[a] - px[b]) + abs(py[a] - py[b]);

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

    int todos = (1 << N) - 1, melhor = INF, ultimo = 0;
    for (int j = 1; j < N; j++)
        if (dp[todos][j] + d[j][0] < melhor) melhor = dp[todos][j] + d[j][0], ultimo = j; // com a volta
    printf("Menor volta: %d quarteirões (último cliente: %s)\n", melhor, pontos[ultimo]);
    return 0;
}
