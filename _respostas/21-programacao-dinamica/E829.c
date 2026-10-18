// 0139 · Troco com programação dinâmica
// Exercício E829 · ★☆☆

#include <stdio.h>

#define PEDIDO 25

int main(void) {
    int pacote[] = {3, 7, 11};
    int k = 3;
    int inf = PEDIDO + 1; // nunca se compram mais que PEDIDO pacotes
    int dp[PEDIDO + 1];

    dp[0] = 0;
    for (int v = 1; v <= PEDIDO; v++) {
        dp[v] = inf;
        for (int p = 0; p < k; p++) {
            if (pacote[p] <= v && dp[v - pacote[p]] + 1 < dp[v]) {
                dp[v] = dp[v - pacote[p]] + 1;
            }
        }
    }

    printf("Impossíveis até %d:", PEDIDO);
    for (int v = 1; v <= PEDIDO; v++) {
        if (dp[v] >= inf) {
            printf(" %d", v);
        }
    }
    printf("\nMenor número de pacotes para %d parafusos: %d\n", PEDIDO, dp[PEDIDO]);
    return 0;
}
