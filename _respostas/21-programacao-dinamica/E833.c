// 0139 · Troco com programação dinâmica
// Exercício E833 · ★★★
//
// Resposta: o "infinito" era INT_MAX. Para v = 1, 2, 3, 5, 6, 9..., que não
// têm solução, dp[v] fica INT_MAX, e depois a conta dp[v - lata[c]] + 1 faz
// INT_MAX + 1: estouro de int com sinal (comportamento indefinido, que o
// UBSan acusa). Sem o sanitizer, na prática vira INT_MIN, que "ganha" no
// < e espalha números negativos pela tabela. Conserto: só somar quando o resto
// tem solução (dp[v - lata[c]] != INF). Trocar INF por TOTAL + 1 também
// resolve.

#include <limits.h>
#include <stdio.h>

#define TOTAL 15
#define INF INT_MAX

int main(void) {
    int lata[] = {4, 7};
    int k = 2;
    int dp[TOTAL + 1];

    dp[0] = 0;
    for (int v = 1; v <= TOTAL; v++) {
        dp[v] = INF;
        for (int c = 0; c < k; c++) {
            if (lata[c] <= v && dp[v - lata[c]] != INF && dp[v - lata[c]] + 1 < dp[v]) {
                dp[v] = dp[v - lata[c]] + 1;
            }
        }
    }

    for (int v = 1; v <= TOTAL; v++) {
        if (dp[v] == INF) {
            printf("%2d L: impossível\n", v);
        } else {
            printf("%2d L: %d lata%s\n", v, dp[v], dp[v] > 1 ? "s" : "");
        }
    }
    return 0;
}
