// Lista · Módulo 21 · Programação dinâmica
// Exercício P2120 · ★★☆ · Quantas árvores de busca diferentes?

#include <stdio.h>

#define MAX 16

long long memo[MAX];
int calculos = 0;

long long arv(int n) {
    if (memo[n] >= 0) {
        return memo[n];
    }
    calculos++;
    long long s = 0;
    if (n == 0) {
        s = 1;
    }
    for (int r = 1; r <= n; r++) {
        s += arv(r - 1) * arv(n - r);
    }
    memo[n] = s;
    return s;
}

int main(void) {
    for (int i = 0; i < MAX; i++) {
        memo[i] = -1;
    }
    for (int n = 1; n < MAX; n++) {
        printf("%2d chaves: %lld árvores\n", n, arv(n));
    }
    printf("Cálculos: %d\n", calculos);
    return 0;
}
