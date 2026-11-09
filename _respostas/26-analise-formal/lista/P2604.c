// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2604 · ★☆☆ · Turno e returno

#include <stdio.h>

long jogos(int n) {
    long total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                total++;
            }
        }
    }
    return total;
}

int main(void) {
    int ns[] = {4, 20, 380};
    for (int k = 0; k < 3; k++) {
        long n = ns[k];
        printf("n = %3ld: %6ld jogos, n(n-1) = %6ld\n", n, jogos(ns[k]), n * (n - 1));
    }
    return 0;
}
