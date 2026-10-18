// 0070 · Bits, máscaras e flags
// Exercício E417 · ★★☆

#include <stdint.h>
#include <stdio.h>

void mostrar_bits(uint16_t x) {
    for (int b = 15; b >= 0; b--) {
        printf("%u", (x >> b) & 1u);
        if (b % 4 == 0 && b > 0) {
            printf(" ");
        }
    }
}

int contar_uns(uint16_t x) {
    int n = 0;
    while (x != 0) {
        n += x & 1u;
        x >>= 1;
    }
    return n;
}

int main(void) {
    uint16_t valores[] = {2025, 255, 4096};

    for (int i = 0; i < 3; i++) {
        int uns = contar_uns(valores[i]);
        printf("%u: ", (unsigned)valores[i]);
        mostrar_bits(valores[i]);
        printf(" -> %d bits 1 (%s)\n", uns, (uns & 1) ? "ímpar" : "par");
    }
    return 0;
}
