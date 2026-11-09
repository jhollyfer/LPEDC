// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2605 · ★☆☆ · Quantas vezes dá para dividir

#include <stdio.h>
#include <math.h>

int cortes(long n) {
    int c = 0;
    while (n > 1) {
        n /= 2;
        c++;
    }
    return c;
}

int main(void) {
    long ns[] = {1, 2, 1000, 1024, 1000000};
    for (int k = 0; k < 5; k++) {
        printf("n = %7ld: %2d cortes, floor(log2 n) = %2d\n", ns[k], cortes(ns[k]),
               (int)floor(log2((double)ns[k])));
    }
    return 0;
}
