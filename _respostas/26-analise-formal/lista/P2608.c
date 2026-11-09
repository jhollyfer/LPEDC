// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2608 · ★☆☆ · Soma dos ímpares

#include <stdio.h>

int main(void) {
    long ns[] = {10, 100, 5000};
    for (int k = 0; k < 3; k++) {
        long n = ns[k];
        long soma = 0, voltas = 0;
        for (long i = 1; i < 2 * n; i += 2) {
            soma += i;
            voltas++;
        }
        printf("n = %4ld: %8ld tijolos em %4ld voltas, n² = %8ld\n", n, soma, voltas, n * n);
    }
    return 0;
}
