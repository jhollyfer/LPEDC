// Lista · Módulo 01 · Fundamentos de C
// Exercício P0124 · ★★★ · O dígito do código de barras

#include <stdio.h>

int main(void) {
    long long n = 789123456789LL;

    int d1 = (int)(n / 100000000000LL % 10);
    int d2 = (int)(n / 10000000000LL % 10);
    int d3 = (int)(n / 1000000000LL % 10);
    int d4 = (int)(n / 100000000LL % 10);
    int d5 = (int)(n / 10000000LL % 10);
    int d6 = (int)(n / 1000000LL % 10);
    int d7 = (int)(n / 100000LL % 10);
    int d8 = (int)(n / 10000LL % 10);
    int d9 = (int)(n / 1000LL % 10);
    int d10 = (int)(n / 100LL % 10);
    int d11 = (int)(n / 10LL % 10);
    int d12 = (int)(n % 10);

    int soma = (d1 + d3 + d5 + d7 + d9 + d11) + 3 * (d2 + d4 + d6 + d8 + d10 + d12);
    int verificador = (10 - soma % 10) % 10;

    printf("Soma ponderada: %d\n", soma);
    printf("Verificador: %d\n", verificador);
    printf("Código: %lld\n", n * 10 + verificador);
    return 0;
}
