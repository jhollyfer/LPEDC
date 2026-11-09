// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2723 · ★★★ · O sensor que manda bytes

#include <stdint.h>
#include <stdio.h>

int de_byte(uint8_t b) {
    return b >= 128 ? b - 256 : b;
}

uint8_t para_byte(int v) {
    return (uint8_t)v; // para sem sinal: soma 256 aos negativos
}

int de_12_bits(unsigned x) {
    x &= 0xFFFu;
    return (x & 0x800u) ? (int)x - 4096 : (int)x;
}

int main(void) {
    uint8_t leituras[] = {0x00, 0x7F, 0x80, 0xFF, 0xF6};
    for (int i = 0; i < 5; i++) {
        printf("0x%02X -> %d\n", leituras[i], de_byte(leituras[i]));
    }
    printf("-10 -> 0x%02X\n", para_byte(-10));
    printf("12 bits: 0x7FF -> %d, 0xFF6 -> %d\n", de_12_bits(0x7FFu), de_12_bits(0xFF6u));
    return 0;
}
