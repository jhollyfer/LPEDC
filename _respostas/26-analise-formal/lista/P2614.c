// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2614 · ★★☆ · A rede que triplica

#include <stdio.h>

int main(void) {
    long ns[] = {100, 1000, 1000000};
    for (int k = 0; k < 3; k++) {
        long n = ns[k];
        long total = 0, ultima = 1;
        for (long t = 1; t <= n; t *= 3) {
            for (long j = 0; j < t; j++) {
                total++;
            }
            ultima = t;
        }
        printf("n = %7ld: total %6ld, fórmula %6ld, razão %.3f\n", n, total,
               (3 * ultima - 1) / 2, (double)total / n);
    }
    return 0;
}
