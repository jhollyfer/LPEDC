// A377 · Até onde o exato aguenta

#include <stdio.h>
#include <stdlib.h>

#define MAXN 16
#define INF 1000000000

int n, d[MAXN][MAXN];
int dp[1 << MAXN][MAXN]; // 4 MB: global, fora da pilha

long held_karp(int *custo) {
    long passos = 0;
    for (int s = 0; s < (1 << n); s++)
        for (int j = 0; j < n; j++) dp[s][j] = INF;
    dp[1][0] = 0;
    for (int s = 1; s < (1 << n); s += 2)
        for (int j = 0; j < n; j++) {
            if (!(s >> j & 1) || dp[s][j] == INF) continue;
            for (int k = 1; k < n; k++) {
                if (s >> k & 1) continue;
                passos++;
                int t = s | 1 << k, c = dp[s][j] + d[j][k];
                if (c < dp[t][k]) dp[t][k] = c;
            }
        }
    *custo = INF;
    for (int j = 1; j < n; j++)
        if (dp[(1 << n) - 1][j] + d[j][0] < *custo) *custo = dp[(1 << n) - 1][j] + d[j][0];
    return passos;
}

int main(void) {
    unsigned semente = 2024; // gerador simples: os mesmos pontos em toda execução
    int px[MAXN], py[MAXN];
    for (int i = 0; i < MAXN; i++) {
        semente = semente * 1103515245u + 12345u;
        px[i] = (int)(semente >> 16) % 20;
        semente = semente * 1103515245u + 12345u;
        py[i] = (int)(semente >> 16) % 20;
    }
    printf(" n  rota ótima  passos Held-Karp  memória da tabela  (n-1)! rotas\n");
    for (n = 4; n <= MAXN; n += 4) {
        for (int a = 0; a < n; a++)
            for (int b = 0; b < n; b++) d[a][b] = abs(px[a] - px[b]) + abs(py[a] - py[b]);
        int custo;
        long passos = held_karp(&custo);
        double fat = 1;
        for (int k = 2; k < n; k++) fat *= k;
        printf("%2d  %10d  %16ld  %14.1f KB  %12.0f\n", n, custo, passos,
               (double)(1 << n) * n * sizeof(int) / 1024, fat);
    }
    printf("Para n = 25: tabela de %.1f GB\n", (double)(1 << 25) * 25 * sizeof(int) / (1024.0 * 1024 * 1024));
    return 0;
}
// Saída:
//  n  rota ótima  passos Held-Karp  memória da tabela  (n-1)! rotas
//  4          52                15             0.2 KB             6
//  8          66              1351             8.0 KB          5040
// 12          74             56331           192.0 KB      39916800
// 16          78           1720335          4096.0 KB  1307674368000
// Para n = 25: tabela de 3.1 GB
//
// Os pontos vêm de um gerador linear congruente com semente fixa: a saída
// é sempre a mesma. Cada 4 pontos a mais multiplicam os passos do
// Held-Karp por 30 a 90 e a memória por 16 x (n+4)/n; a força bruta
// multiplica por milhares. Em 16 pontos, 1,7 milhão de passos contra 1,3
// trilhão de rotas. Mas a tabela cresce junto: com 25 pontos ela já não
// cabe na memória de um notebook comum, e o exato para de ser opção.
