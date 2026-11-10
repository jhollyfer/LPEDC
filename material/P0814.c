// Lista · Módulo 08 · Tipos compostos
// Exercício P0814 · ★★☆ · A cor em 16 bits
//
// Telas pequenas (como a de uma maquininha de cartão) guardam cada cor em 16
// bits no formato RGB565: 5 bits de vermelho (bits 15 a 11), 6 de verde (10 a
// 5) e 5 de azul (4 a 0). Partindo de uma cor de 8 bits por canal (0 a 255),
// escreva:
//
//   uint16_t para_565(int r, int g, int b);   // guarda os bits mais altos
//   void de_565(uint16_t c, int *r, int *g, int *b);  // volta para 0..255
//
// Para converter, jogue fora os bits de baixo: r >> 3 (fica com 5 bits),
// g >> 2 (6 bits), b >> 3. Para voltar, desloque para a esquerda e repita os
// bits de cima nos de baixo: r8 = (r5 << 3) | (r5 >> 2) (e g8 = (g6 << 2) |
// (g6 >> 4)). Converta as cores abaixo, mostrando o valor em hexa e a cor
// recuperada (algumas perdem um pouco de precisão):
//
//   laranja (255, 136, 0), verde-bandeira (0, 156, 59), branco (255, 255, 255)
//
//   Saída esperada:
//   laranja        (255, 136,   0) -> 0xFC40 -> (255, 138,   0)
//   verde-bandeira (  0, 156,  59) -> 0x04E7 -> (  0, 158,  57)
//   branco         (255, 255, 255) -> 0xFFFF -> (255, 255, 255)
//
// Dicas:
// 1. Montar: (uint16_t) (((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3)).
// 2. Separar: r5 = (c >> 11) & 0x1F; g6 = (c >> 5) & 0x3F; b5 = c & 0x1F.
// 3. 0x1F são 5 bits ligados (31) e 0x3F são 6 (63).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdint.h>

int main(void) {

    return 0;
}
