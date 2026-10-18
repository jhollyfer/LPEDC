// 0138 · Memoização
// Exercício E824 · ★☆☆

#include <stdio.h>

#define MAX 150

long long chamadas = 0;
long long memo[MAX + 1];

long long calcada_rec(int n) {
    chamadas++;
    if (n == 0 || n == 2) {
        return 1;
    }
    if (n == 1) {
        return 0;
    }
    return calcada_rec(n - 2) + calcada_rec(n - 3);
}

long long calcada_memo(int n) {
    chamadas++;
    if (n == 0 || n == 2) {
        return 1;
    }
    if (n == 1) {
        return 0;
    }
    if (memo[n] != -1) {
        return memo[n];              // já calculado: só consulta
    }
    memo[n] = calcada_memo(n - 2) + calcada_memo(n - 3);
    return memo[n];
}

int main(void) {
    chamadas = 0;
    long long r = calcada_rec(40);
    printf("recursão pura: c(40) = %lld com %lld chamadas\n", r, chamadas);

    for (int i = 0; i <= MAX; i++) {
        memo[i] = -1;
    }
    chamadas = 0;
    r = calcada_memo(40);
    printf("memoização:    c(40) = %lld com %lld chamadas\n", r, chamadas);
    printf("memoização:    c(120) = %lld\n", calcada_memo(120));
    return 0;
}
