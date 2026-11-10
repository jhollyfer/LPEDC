// 0189 · Juntando tudo
// Exercício E1132 · ★★☆
//
// Escreva o Held-Karp para a padaria do E1129 (cinco pontos, distância
// |dx| + |dy|) com a tabela dp[1 << N][N], sem guardar a tabela de
// anteriores (a memória do servidor não comporta outra do mesmo tamanho).
// Mostre a menor volta e reconstrua a rota só com dp[][]: o ponto que veio
// antes de k no conjunto s é o primeiro j (de s sem k) tal que
// dp[s sem k][j] + d[j][k] == dp[s][k]. Comece em (todos, fim) e ande para
// trás até sobrar só a padaria. No empate do último ponto, vale o menor
// índice.
//
//   Saída esperada:
//   Menor volta: 22 quarteirões
//   Rota: Padaria Feira Escola Posto Banco Padaria
//
// Escreva sua resposta abaixo:

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

    return 0;
}
