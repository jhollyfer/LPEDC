// 0069 · Union
// Exercício E414 · ★★★
//
// Resposta. Na memória, little-endian guarda 44 33 22 11 e big-endian guarda
// 11 22 33 44.
// Little-endian (o seu PC): m[0] = 0x3344, m[1] = 0x1122; b[0] = 0x44,
// b[3] = 0x11; trocar b[0] troca o byte menos significativo: n = 0x112233FF.
// Big-endian: m[0] = 0x1122, m[1] = 0x3344; b[0] = 0x11, b[3] = 0x44; b[0] é
// o byte mais significativo: n = 0xFF223344.

#include <stdint.h>
#include <stdio.h>

typedef union {
    uint32_t n;
    uint16_t m[2];
    unsigned char b[4];
} Visao;

int main(void) {
    Visao x;
    x.n = 0x11223344;
    printf("m[0] = 0x%04X, m[1] = 0x%04X\n", (unsigned)x.m[0], (unsigned)x.m[1]);
    printf("b[0] = 0x%02X, b[3] = 0x%02X\n", x.b[0], x.b[3]);
    x.b[0] = 0xFF;
    printf("n = 0x%08X\n", (unsigned)x.n);
    return 0;
}
