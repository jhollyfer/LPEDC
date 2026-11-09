// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1006 · ★☆☆ · Quantos dígitos tem o valor do boleto

#include <stdio.h>

int digitos(long long n, int *passos) {
    int cont = 0;
    *passos = 0;
    do {
        n = n / 10;
        (*passos)++;
        cont++;
    } while (n > 0);
    return cont;
}

int main(void) {
    long long testes[6] = {0, 7, 70, 7000, 7000000, 7000000000LL};
    for (int i = 0; i < 6; i++) {
        int passos;
        int d = digitos(testes[i], &passos);
        printf("%lld: %d dígito(s), %d divisões\n", testes[i], d, passos);
    }
    return 0;
}
