// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1713 · ★★☆ · Quando o mestre não serve: 2T(n/2) + n lg n

#include <stdio.h>

long custo;

int lg(long n) {
    int k = 0;
    while (n > 1) {
        n /= 2;
        k++;
    }
    return k;
}

void relatorio(long n) {
    if (n == 1) {
        custo++;
        return;
    }
    custo += n * lg(n); // juntar as metades custa n lg n
    relatorio(n / 2);
    relatorio(n / 2);
}

int main(void) {
    printf("    n      custo    fórmula  c/(n lg n)  c/(n lg² n)\n");
    for (int k = 1; k <= 16; k++) {
        long n = 1L << k;
        custo = 0;
        relatorio(n);
        long formula = n + n * k * (k + 1) / 2;
        printf("%5ld %10ld %10ld %11.3f %12.3f\n", n, custo, formula,
               (double)custo / ((double)n * k), (double)custo / ((double)n * k * k));
    }
    return 0;
}
