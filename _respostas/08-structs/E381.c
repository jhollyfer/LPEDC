// 0064 · Union
// Exercício E381 · ★★☆

#include <stdint.h>
#include <stdio.h>

typedef union {
    uint16_t valor;
    unsigned char b[2];
} Dois;

uint16_t trocar_bytes(uint16_t x) {
    Dois d;
    d.valor = x;
    unsigned char tmp = d.b[0];
    d.b[0] = d.b[1];
    d.b[1] = tmp;
    return d.valor;
}

int main(void) {
    printf("0x%04X -> 0x%04X\n", 0xABCDu, (unsigned)trocar_bytes(0xABCD));
    printf("0x%04X -> 0x%04X\n", 0x0102u, (unsigned)trocar_bytes(0x0102));
    printf("%d -> %d\n", 258, trocar_bytes(258));
    return 0;
}
