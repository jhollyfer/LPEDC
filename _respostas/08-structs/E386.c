// 0065 · Bits, máscaras e flags
// Exercício E386 · ★☆☆

#include <stdio.h>

int main(void) {
    unsigned numeros[] = {7, 12, 25, 40};

    for (int i = 0; i < 4; i++) {
        unsigned n = numeros[i];
        printf("%u: %s, x8 = %u, /4 = %u\n", n, (n & 1u) ? "ímpar" : "par", n << 3, n >> 2);
    }
    return 0;
}
