// Lista · Módulo 01 · Fundamentos de C
// Exercício P0130 · ★★★ · Os quatro bytes de um int

#include <stdio.h>

int main(void) {
    int n = 305419896;

    int b3 = n / 16777216;      // 256 * 256 * 256
    int b2 = n / 65536 % 256;   // 256 * 256
    int b1 = n / 256 % 256;
    int b0 = n % 256;

    int remontado = b3 * 16777216 + b2 * 65536 + b1 * 256 + b0;

    printf("Número: %d (0x%X)\n", n, n);
    printf("Bytes: %d %d %d %d\n", b3, b2, b1, b0);
    printf("Em hexa: %02X %02X %02X %02X\n", b3, b2, b1, b0);
    printf("Remontado: %d\n", remontado);
    return 0;
}
