// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2611 · ★★☆ · O sanduíche completo

#include <stdio.h>

#define LIMITE 100000

long custo(long n) {
    return 4 * n * n + 30 * n + 100;
}

long n0_teto(double c) {
    long n0 = 1;
    for (long n = 1; n <= LIMITE; n++) {
        if (custo(n) > c * n * n) {
            n0 = n + 1;
        }
    }
    return n0;
}

long n0_piso(double c) {
    long n0 = 1;
    for (long n = 1; n <= LIMITE; n++) {
        if (custo(n) < c * n * n) {
            n0 = n + 1;
        }
    }
    return n0;
}

int main(void) {
    double tetos[] = {5, 6, 8};
    for (int i = 0; i < 3; i++) {
        printf("teto c = %.0f: n0 = %ld\n", tetos[i], n0_teto(tetos[i]));
    }
    printf("piso c = 4: n0 = %ld\n", n0_piso(4));
    printf("Θ(n²) com c1 = 4, c2 = 5 e n0 = %ld\n", n0_teto(5));
    return 0;
}
