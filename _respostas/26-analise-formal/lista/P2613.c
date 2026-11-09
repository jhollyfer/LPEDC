// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2613 · ★★☆ · Cubos de gelo

#include <stdio.h>

long cubinhos(int n) {
    long total = 0;
    for (long i = 1; i <= n; i++) {
        for (long j = 0; j < i * i * i; j++) {
            total++;
        }
    }
    return total;
}

int main(void) {
    int ns[] = {4, 10, 50};
    for (int k = 0; k < 3; k++) {
        long n = ns[k];
        long s = n * (n + 1) / 2;
        printf("n = %2ld: %8ld cubinhos, fórmula %8ld\n", n, cubinhos(ns[k]), s * s);
    }
    return 0;
}
