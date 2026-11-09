// Lista · Módulo 01 · Fundamentos de C
// Exercício P0121 · ★★★ · Os dígitos verificadores do CPF

#include <stdio.h>

int main(void) {
    int base = 123456789;

    int d1 = base / 100000000;
    int d2 = base / 10000000 % 10;
    int d3 = base / 1000000 % 10;
    int d4 = base / 100000 % 10;
    int d5 = base / 10000 % 10;
    int d6 = base / 1000 % 10;
    int d7 = base / 100 % 10;
    int d8 = base / 10 % 10;
    int d9 = base % 10;

    int soma1 = d1 * 10 + d2 * 9 + d3 * 8 + d4 * 7 + d5 * 6 + d6 * 5 + d7 * 4 + d8 * 3 + d9 * 2;
    int resto1 = soma1 % 11;
    int dv1 = (11 - resto1) % 11 % 10; // resto 0 ou 1 vira 0

    int soma2 = d1 * 11 + d2 * 10 + d3 * 9 + d4 * 8 + d5 * 7 + d6 * 6 + d7 * 5 + d8 * 4 + d9 * 3 + dv1 * 2;
    int resto2 = soma2 % 11;
    int dv2 = (11 - resto2) % 11 % 10;

    printf("Soma 1: %d, resto %d, dígito %d\n", soma1, resto1, dv1);
    printf("Soma 2: %d, resto %d, dígito %d\n", soma2, resto2, dv2);
    printf("CPF: %03d.%03d.%03d-%d%d\n", base / 1000000, base / 1000 % 1000, base % 1000, dv1, dv2);
    return 0;
}
