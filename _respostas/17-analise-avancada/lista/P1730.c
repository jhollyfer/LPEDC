// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1730 · ★★★ · Contador em que trocar o bit i custa 2^i

#include <stdio.h>

#define K 24

int b[K];

void incrementa(long *comum, long *pesado) {
    int i = 0;
    while (i < K && b[i] == 1) {
        b[i] = 0;
        *comum += 1;
        *pesado += 1L << i; // a placa i custa 2^i
        i++;
    }
    if (i < K) {
        b[i] = 1;
        *comum += 1;
        *pesado += 1L << i;
    }
}

int main(void) {
    printf("      n    comum      pesado  n(lg n + 1)  pesado/n\n");
    for (int k = 4; k <= 20; k += 4) {
        long n = 1L << k, comum = 0, pesado = 0;
        for (int i = 0; i < K; i++) b[i] = 0;
        for (long t = 0; t < n; t++) incrementa(&comum, &pesado);
        printf("%7ld %8ld %11ld %12ld %9.1f\n", n, comum, pesado, n * (k + 1), (double)pesado / n);
    }
    return 0;
}
