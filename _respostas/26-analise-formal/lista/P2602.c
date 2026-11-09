// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2602 · ★☆☆ · O n₀ do frete

#include <stdio.h>

#define LIMITE 10000

long custo(long n) {
    return 2 * n + 100;
}

long acha_n0(long c) {
    long n0 = 1;
    for (long n = 1; n <= LIMITE; n++) {
        if (custo(n) > c * n) {
            n0 = n + 1;
        }
    }
    return n0;
}

int main(void) {
    long cs[] = {3, 4, 12, 102};
    for (int i = 0; i < 4; i++) {
        printf("c = %3ld: n0 = %ld\n", cs[i], acha_n0(cs[i]));
    }
    return 0;
}
