// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2615 · ★★☆ · Os passos do crivo

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    long ns[] = {100, 10000, 1000000};
    for (int k = 0; k < 3; k++) {
        long n = ns[k];
        char *composto = calloc(n + 1, 1);
        if (composto == NULL) {
            return 1;
        }
        long marcacoes = 0;
        for (long p = 2; p * p <= n; p++) {
            if (!composto[p]) {
                for (long m = p * p; m <= n; m += p) {
                    composto[m] = 1;
                    marcacoes++;
                }
            }
        }
        long primos = 0;
        for (long i = 2; i <= n; i++) {
            primos += !composto[i];
        }
        free(composto);
        printf("n = %7ld: %6ld primos, %7ld marcações, razão %.3f\n", n, primos, marcacoes,
               marcacoes / (n * log(log((double)n))));
    }
    return 0;
}
