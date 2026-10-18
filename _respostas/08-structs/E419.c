// 0070 · Bits, máscaras e flags
// Exercício E419 · ★★★

#include <stdint.h>
#include <stdio.h>

uint32_t rgb(unsigned r, unsigned g, unsigned b) {
    return (r << 16) | (g << 8) | b;
}

unsigned canal_r(uint32_t c) { return (c >> 16) & 0xFF; }
unsigned canal_g(uint32_t c) { return (c >> 8) & 0xFF; }
unsigned canal_b(uint32_t c) { return c & 0xFF; }

uint32_t escurecer(uint32_t c) {
    return rgb(canal_r(c) >> 1, canal_g(c) >> 1, canal_b(c) >> 1);
}

uint32_t cinza(uint32_t c) {
    unsigned m = (canal_r(c) + canal_g(c) + canal_b(c)) / 3;
    return rgb(m, m, m);
}

int main(void) {
    uint32_t laranja = rgb(255, 136, 0);
    uint32_t azul = 0x3366CC;

    printf("rgb(255, 136, 0) = #%06X\n", (unsigned)laranja);
    printf("#%06X -> r = %u, g = %u, b = %u\n", (unsigned)azul, canal_r(azul), canal_g(azul), canal_b(azul));
    printf("#%06X escurecida = #%06X\n", (unsigned)laranja, (unsigned)escurecer(laranja));
    printf("#%06X em cinza = #%06X\n", (unsigned)azul, (unsigned)cinza(azul));
    return 0;
}
