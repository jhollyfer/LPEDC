// 0139 · Troco com programação dinâmica
// Exercício E831 · ★★☆

#include <stdio.h>

#define MAX 20

int pacote[] = {1, 6, 10};
int k = 3;

// pega sempre o maior pacote que cabe
int guloso(int v) {
    int usados = 0;
    for (int p = k - 1; p >= 0; p--) {
        while (pacote[p] <= v) {
            v -= pacote[p];
            usados++;
        }
    }
    return usados;
}

int main(void) {
    int inf = MAX + 1;
    int dp[MAX + 1], ultimo[MAX + 1];

    dp[0] = 0;
    for (int v = 1; v <= MAX; v++) {
        dp[v] = inf;
        for (int p = 0; p < k; p++) {
            if (pacote[p] <= v && dp[v - pacote[p]] + 1 < dp[v]) {
                dp[v] = dp[v - pacote[p]] + 1;
                ultimo[v] = pacote[p]; // o pacote que deu o mínimo
            }
        }
    }
    printf("12 gemas: %d pacotes (", dp[12]);
    for (int v = 12; v > 0; v -= ultimo[v]) {
        printf("%d%s", ultimo[v], v - ultimo[v] > 0 ? " " : "");
    }
    printf(")\n");

    for (int v = 1; v <= MAX; v++) {
        int g = guloso(v);
        if (g > dp[v]) {
            printf("%d: guloso %d, PD %d\n", v, g, dp[v]);
        }
    }
    return 0;
}
