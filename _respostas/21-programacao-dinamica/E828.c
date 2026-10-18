// 0138 · Memoização
// Exercício E828 · ★★★

#include <stdio.h>

#define MAX 60

long long memo[MAX + 1][MAX + 1];
long long chamadas = 0;

// C(n, k): escolher k dezenas entre n
long long comb(int n, int k) {
    chamadas++;
    if (k == 0 || k == n) {
        return 1;
    }
    if (memo[n][k] != -1) {
        return memo[n][k];
    }
    // a dezena n entra (sobram k - 1 para escolher entre n - 1)
    // ou não entra (as k saem das n - 1 restantes)
    memo[n][k] = comb(n - 1, k - 1) + comb(n - 1, k);
    return memo[n][k];
}

int main(void) {
    for (int n = 0; n <= MAX; n++) {
        for (int k = 0; k <= MAX; k++) {
            memo[n][k] = -1;
        }
    }

    long long r = comb(60, 6);
    printf("Mega-Sena: C(60, 6) = %lld (%lld chamadas)\n", r, chamadas);
    printf("chance de acertar com um jogo: 1 em %lld\n", r);

    chamadas = 0;
    r = comb(60, 30);
    printf("C(60, 30) = %lld (%lld chamadas novas)\n", r, chamadas);

    int guardados = 0;
    for (int n = 0; n <= MAX; n++) {
        for (int k = 0; k <= MAX; k++) {
            if (memo[n][k] != -1) {
                guardados++;
            }
        }
    }
    printf("subproblemas guardados no memo: %d\n", guardados);
    return 0;
}
