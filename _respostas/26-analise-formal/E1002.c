// 0167 · Somatórios que saem de laços
// Exercício E1002 · ★★★

#include <stdio.h>
#include <math.h>

// o fiscal p visita as bancas p, 2p, 3p, ... de uma feira com n bancas
long visitas(long n) {
    long total = 0;
    for (long p = 1; p <= n; p++) {
        for (long banca = p; banca <= n; banca += p) {
            total++;
        }
    }
    return total;
}

// o mesmo total sem o laço de dentro: o fiscal p visita n / p bancas
long visitas_rapido(long n) {
    long total = 0;
    for (long p = 1; p <= n; p++) {
        total += n / p;
    }
    return total;
}

int main(void) {
    printf("      n    visitas    rápido    n ln n  razão\n");
    for (long n = 10; n <= 1000000; n *= 10) {
        long v = visitas(n);
        double nln = n * log((double)n);
        printf("%7ld %10ld %9ld %9.0f %6.3f\n", n, v, visitas_rapido(n), nln, v / nln);
    }
    return 0;
}
