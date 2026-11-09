// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1008 · ★☆☆ · O polinômio pelo jeito de Horner

#include <stdio.h>

long ingenuo(const int c[], int grau, int x, int *mult) {
    long soma = 0;
    *mult = 0;
    for (int k = 0; k <= grau; k++) {
        long pot = 1;
        for (int j = 0; j < k; j++) {
            pot *= x;
            (*mult)++;
        }
        soma += c[k] * pot;
        (*mult)++;
    }
    return soma;
}

long horner(const int c[], int grau, int x, int *mult) {
    long r = c[grau];
    *mult = 0;
    for (int k = grau - 1; k >= 0; k--) {
        r = r * x + c[k];
        (*mult)++;
    }
    return r;
}

int main(void) {
    int c[5] = {-7, 5, 0, -3, 2};
    int m1, m2;
    long a = ingenuo(c, 4, 3, &m1);
    long b = horner(c, 4, 3, &m2);
    printf("Ingênuo: p(3) = %ld com %d multiplicações\n", a, m1);
    printf("Horner:  p(3) = %ld com %d multiplicações\n", b, m2);
    return 0;
}
