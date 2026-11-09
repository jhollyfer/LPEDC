// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2808 · ★☆☆ · Multiplicação em ponto flutuante

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int h(unsigned k, int m) {
    double A = (sqrt(5.0) - 1) / 2;
    double p = k * A;
    return (int)(m * (p - floor(p)));
}

int main(void) {
    bool usado_mult[8] = {false}, usado_div[8] = {false};
    int a = 0, b = 0;
    printf("senha | mult | k %% 8\n");
    for (unsigned k = 10; k <= 80; k += 10) {
        int x = h(k, 8), y = (int)(k % 8);
        printf("%5u | %4d | %d\n", k, x, y);
        a += !usado_mult[x];
        b += !usado_div[y];
        usado_mult[x] = usado_div[y] = true;
    }
    printf("baldes usados: multiplicação %d, divisão %d\n", a, b);
    return 0;
}
