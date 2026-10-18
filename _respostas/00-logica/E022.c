// 0004 · Binário, hexadecimal, bit e byte
// Exercício E022 · ★★☆
//
// Resposta: R = 255, G = 136, B = 0. #808080 é cinza médio (128, 128, 128): os três componentes iguais sempre dão um tom de cinza.

#include <stdio.h>

int main(void) {
    int r = 0xFF, g = 0x88, b = 0x00;
    printf("R = %d, G = %d, B = %d\n", r, g, b);
    return 0;
}
