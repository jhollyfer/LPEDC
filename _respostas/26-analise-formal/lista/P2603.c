// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2603 · ★☆☆ · Piso do sorteio de duplas

#include <stdio.h>

#define LIMITE 10000

long custo(long n) {
    return n * n - 20 * n;
}

long acha_n0(double c) {
    long n0 = 1;
    for (long n = 1; n <= LIMITE; n++) {
        if (custo(n) < c * n * n) {
            n0 = n + 1;
        }
    }
    return n0;
}

int main(void) {
    double cs[] = {0.5, 0.75, 0.9};
    for (int i = 0; i < 3; i++) {
        printf("c = %.2f: n0 = %ld\n", cs[i], acha_n0(cs[i]));
    }
    return 0;
}
