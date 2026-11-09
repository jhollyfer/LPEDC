// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2618 · ★★☆ · Potência sem pilha

#include <stdio.h>

#define MOD 1000000007L

long multiplicacoes = 0;

// quadrados sucessivos: Θ(log e) de tempo, Θ(1) de espaço
long potencia(long base, long e) {
    long r = 1;
    base %= MOD;
    while (e > 0) {
        if (e % 2 == 1) {
            r = r * base % MOD;
            multiplicacoes++;
        }
        base = base * base % MOD;
        multiplicacoes++;
        e /= 2;
    }
    return r;
}

int main(void) {
    long es[] = {10, 1000, 1000000000};
    for (int i = 0; i < 3; i++) {
        multiplicacoes = 0;
        long r = potencia(3, es[i]);
        printf("3^%ld mod p = %ld, %ld multiplicações\n", es[i], r, multiplicacoes);
    }
    return 0;
}
