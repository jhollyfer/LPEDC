// Lista · Módulo 21 · Programação dinâmica
// Exercício P2101 · ★☆☆ · Tribonacci com e sem memória

#include <stdio.h>

#define MAX 64

long chamadas;

long long trib(int n) {
    chamadas++;
    if (n < 2) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    return trib(n - 1) + trib(n - 2) + trib(n - 3);
}

long long memo[MAX];

long long trib_memo(int n) {
    chamadas++;
    if (memo[n] >= 0) {
        return memo[n];
    }
    long long r;
    if (n < 2) {
        r = 0;
    } else if (n == 2) {
        r = 1;
    } else {
        r = trib_memo(n - 1) + trib_memo(n - 2) + trib_memo(n - 3);
    }
    memo[n] = r;
    return r;
}

int main(void) {
    chamadas = 0;
    long long r = trib(25);
    printf("Ingênua: T(25) = %lld, %ld chamadas\n", r, chamadas);
    for (int i = 0; i < MAX; i++) {
        memo[i] = -1;
    }
    chamadas = 0;
    r = trib_memo(25);
    printf("Memoizada: T(25) = %lld, %ld chamadas\n", r, chamadas);
    return 0;
}
