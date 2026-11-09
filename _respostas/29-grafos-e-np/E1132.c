// 0189 · Juntando tudo
// Exercício E1132 · ★★☆

#include <stdio.h>
#include <stdlib.h>

#define N 5
#define INF 1000000000

const char *pontos[N] = {"Padaria", "Escola", "Posto", "Banco", "Feira"};
const int px[N] = {0, 3, 5, 1, 4};
const int py[N] = {0, 2, 5, 4, 0};
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
    int todos = (1 << N) - 1, fim = 1;
    for (int j = 2; j < N; j++)
        if (dp[todos][j] + d[j][0] < dp[todos][fim] + d[fim][0]) fim = j;
    printf("Menor volta: %d quarteirões\n", dp[todos][fim] + d[fim][0]);

    // reconstrução sem tabela de anteriores: quem veio antes de k é o j que
    // explica o valor dp[s][k] = dp[s sem k][j] + d[j][k]
    int rota[N], s = todos, k = fim;
    for (int i = N - 1; i > 0; i--) {
        rota[i] = k;
        int sem = s & ~(1 << k);
        int anterior = 0;
        for (int j = 0; j < N; j++)
            if ((sem >> j & 1) && dp[sem][j] != INF && dp[sem][j] + d[j][k] == dp[s][k]) {
                anterior = j;
                break;
            }
        s = sem;
        k = anterior;
    }
    rota[0] = 0;
    printf("Rota:");
    for (int i = 0; i < N; i++) printf(" %s", pontos[rota[i]]);
    printf(" %s\n", pontos[0]);
    return 0;
}
