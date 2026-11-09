// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1725 · ★★★ · O método da substituição testado no computador

#include <math.h>
#include <stdio.h>

#define N 1000000

long T[N + 1];

int main(void) {
    T[1] = 0;
    for (long n = 2; n <= N; n++) T[n] = T[(n + 1) / 2] + T[n / 2] + n - 1; // teto e chão

    printf("      n          T(n)  T/(n lg n)\n");
    for (long n = 10; n <= N; n *= 10) printf("%7ld %13ld %11.3f\n", n, T[n], T[n] / (n * log2((double)n)));

    double maior = 0;
    long onde = 0;
    for (long n = 2; n <= N; n++) {
        double r = T[n] / (n * log2((double)n));
        if (r > maior) {
            maior = r;
            onde = n;
        }
    }
    printf("Maior razão: %.4f, em n = %ld\n", maior, onde);

    long erradas = 0, k = 0, p = 1; // p = 2^k, com k = teto(lg n)
    for (long n = 1; n <= N; n++) {
        while (p < n) {
            p *= 2;
            k++;
        }
        if (T[n] != n * k - p + 1) erradas++;
    }
    printf("Fórmula n teto(lg n) - 2^teto(lg n) + 1: %ld n errados\n", erradas);
    return 0;
}
