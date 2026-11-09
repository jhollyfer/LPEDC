// 0189 · Juntando tudo
// Exercício E1132 · ★★☆
//
// Este Held-Karp para a padaria do E1129 calcula a menor volta, mas não
// guardou a tabela de anteriores, e a memória do servidor não comporta
// outra tabela do mesmo tamanho. Reconstrua a rota só com dp[][]: o
// ponto que veio antes de k no conjunto s é um j (de s sem k) tal que
// dp[s sem k][j] + d[j][k] == dp[s][k]. Comece em (todos, fim) e ande
// para trás até sobrar só a padaria.
//
//   Saída esperada:
//   Menor volta: 22 quarteirões
//   Rota: Padaria Feira Escola Posto Banco Padaria
//
// Dicas:
// 1. s sem k é s & ~(1 << k). Preencha rota[] de trás para frente:
//    rota[N - 1] = fim, depois o anterior, até rota[0] = 0.
// 2. Em caso de empate, fique com o primeiro j (menor índice) que bate.
//    Pule os j fora do conjunto e os que valem INF.
// 3. Resposta esperada: a saída acima. Trocar memória por tempo: cada
//    passo da reconstrução custa O(n) a mais, mas só são n passos.
//
// Escreva sua resposta abaixo (complete o main):

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

    // FALTA: reconstruir a rota só com dp[][] e mostrá-la

    return 0;
}
