// Lista · Módulo 01 · Fundamentos de C
// Exercício P0125 · ★★★ · O byte escrito com zeros e uns

#include <stdio.h>

int main(void) {
    int bits = 10110110; // escrito em decimal, lido como binário

    int b7 = bits / 10000000 % 10;
    int b6 = bits / 1000000 % 10;
    int b5 = bits / 100000 % 10;
    int b4 = bits / 10000 % 10;
    int b3 = bits / 1000 % 10;
    int b2 = bits / 100 % 10;
    int b1 = bits / 10 % 10;
    int b0 = bits % 10;

    int valor = b7 * 128 + b6 * 64 + b5 * 32 + b4 * 16 + b3 * 8 + b2 * 4 + b1 * 2 + b0;

    printf("Bits: %08d\n", bits);
    printf("Decimal: %d\n", valor);
    printf("Hexadecimal: 0x%X\n", valor);
    printf("Octal: 0%o\n", valor);
    return 0;
}
