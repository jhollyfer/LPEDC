// 0069 · Union
// Exercício E414 · ★★★
//
// Preveja a saída deste trecho em DUAS máquinas: o seu PC (little-endian) e
// uma máquina big-endian (como um roteador antigo com processador MIPS).
//
//   typedef union {
//       uint32_t n;
//       uint16_t m[2];
//       unsigned char b[4];
//   } Visao;
//
//   Visao x;
//   x.n = 0x11223344;
//   printf("m[0] = 0x%04X, m[1] = 0x%04X\n", (unsigned)x.m[0], (unsigned)x.m[1]);
//   printf("b[0] = 0x%02X, b[3] = 0x%02X\n", x.b[0], x.b[3]);
//   x.b[0] = 0xFF;
//   printf("n = 0x%08X\n", (unsigned)x.n);
//
// Dicas:
// 1. Desenhe os 4 bytes na memória para cada máquina. Little-endian:
//    44 33 22 11. Big-endian: 11 22 33 44.
// 2. m[0] são os dois primeiros bytes da memória, lidos como um número de 16
//    bits na ordem daquela máquina.
// 3. Resposta esperada. Little-endian: m[0] = 0x3344, m[1] = 0x1122;
//    b[0] = 0x44, b[3] = 0x11; n = 0x112233FF. Big-endian: m[0] = 0x1122,
//    m[1] = 0x3344; b[0] = 0x11, b[3] = 0x44; n = 0xFF223344.
//
// Escreva sua resposta abaixo (como comentário; confira no seu PC a parte
// little-endian):

#include <stdint.h>
#include <stdio.h>

int main(void) {

    return 0;
}
