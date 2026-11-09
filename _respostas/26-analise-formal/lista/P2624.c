// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2624 · ★★★ · Laço que dobra dentro do laço

#include <stdio.h>

int main(void) {
    int ks[] = {4, 10, 16};
    for (int a = 0; a < 3; a++) {
        long k = ks[a];
        long n = 1L << k;
        long x = 0;
        for (long i = 1; i < n; i++) {
            for (long j = 1; j <= i; j *= 2) {
                x++;
            }
        }
        long formula = (k - 1) * n + 1;
        printf("n = %6ld: x = %7ld, fórmula %7ld, razão %.3f\n", n, x, formula,
               (double)x / (n * k));
    }
    return 0;
}
