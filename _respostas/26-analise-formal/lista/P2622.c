// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2622 · ★★★ · Sanduíche com logaritmo

#include <stdio.h>
#include <math.h>

double custo(double n) {
    return n * log2(n) + 5 * n;
}

int main(void) {
    double menor = 1e9, maior = 0;
    for (long n = 2; n <= 100000; n++) {
        double r = custo((double)n) / (n * log2((double)n));
        if (r < menor) menor = r;
        if (r > maior) maior = r;
        if (n == 2 || n == 1024 || n == 100000) {
            printf("n = %6ld: razão %.4f\n", n, r);
        }
    }
    printf("menor %.4f, maior %.4f\n", menor, maior);
    printf("Θ(n log n) com c1 = 1, c2 = 6 e n0 = 2\n");
    return 0;
}
