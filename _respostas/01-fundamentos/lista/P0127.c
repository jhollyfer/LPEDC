// Lista · Módulo 01 · Fundamentos de C
// Exercício P0127 · ★★★ · Fibonacci sem laço

#include <math.h>
#include <stdio.h>

int main(void) {
    const double raiz5 = sqrt(5.0);
    const double phi = (1 + raiz5) / 2;

    long f10 = (long)round(pow(phi, 10) / raiz5);
    long f30 = (long)round(pow(phi, 30) / raiz5);
    long f40 = (long)round(pow(phi, 40) / raiz5);

    printf("phi = %.10f\n", phi);
    printf("F(10) = %ld\n", f10);
    printf("F(30) = %ld\n", f30);
    printf("F(40) = %ld\n", f40);
    return 0;
}
