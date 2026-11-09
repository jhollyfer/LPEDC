// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1718 · ★★☆ · O laço que dobra dentro da recursão

#include <stdio.h>

long custo;

void organiza(long n) {
    if (n == 1) {
        custo++;
        return;
    }
    for (long i = 1; i < n; i *= 2) custo++; // lg n passos
    organiza(n / 2);
    organiza(n / 2);
}

int main(void) {
    printf("      n    custo  3n-lg n-2  custo/n\n");
    for (int k = 0; k <= 20; k += 2) { // potências de 4
        long n = 1L << k;
        custo = 0;
        organiza(n);
        printf("%7ld %8ld %10ld %8.4f\n", n, custo, 3 * n - k - 2, (double)custo / n);
    }
    return 0;
}
