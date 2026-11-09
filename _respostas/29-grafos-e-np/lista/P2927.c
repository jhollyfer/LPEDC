// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2927 · ★★★ · Rota mais curta que termina em casa

#include <stdio.h>
#include <stdlib.h>

#define N 8
#define INF 1000000000

const char *pontos[N] = {"Farmácia", "Ana", "Bruno", "Clara", "Dênis", "Edna", "Fábio", "Gil"};
const int px[N] = {0, 1, 4, 6, 7, 5, 2, 3};
const int py[N] = {0, 3, 4, 3, 0, 1, 6, 1};
int d[N][N], dp[1 << N][N], ant[1 << N][N];

int main(void) {
    for (int a = 0; a < N; a++)
        for (int b = 0; b < N; b++) d[a][b] = abs(px[a] - px[b]) + abs(py[a] - py[b]);
    for (int s = 0; s < (1 << N); s++)
        for (int j = 0; j < N; j++) dp[s][j] = INF;
    dp[1][0] = 0;
    for (int s = 1; s < (1 << N); s += 2)
        for (int j = 0; j < N; j++) {
            if (!(s >> j & 1) || dp[s][j] == INF) continue;
            for (int k = 1; k < N; k++) {
                if (s >> k & 1) continue;
                int t = s | 1 << k, c = dp[s][j] + d[j][k];
                if (c < dp[t][k]) dp[t][k] = c, ant[t][k] = j;
            }
        }
    int todos = (1 << N) - 1, casa = 7;
    int rota[N];
    for (int i = N - 1, s = todos, j = casa; i >= 0; i--) {
        rota[i] = j;
        int a = ant[s][j];
        s &= ~(1 << j);
        j = a;
    }
    printf("Caminho até a casa: %d quarteirões\n", dp[todos][casa]);
    for (int i = 0; i < N; i++) printf("%s%s", pontos[rota[i]], i < N - 1 ? " -> " : "\n");
    printf("Volta fechada era 28; terminar no Gil economiza %d\n", 28 - dp[todos][casa]);
    return 0;
}
