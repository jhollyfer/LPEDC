// 0003 · Tipos e limites
// Exercício E013 · ★☆☆
//
// Resposta: a) 16 + 4 + 2 = 22; b) 255, que é 0xFF; c) 0x1F = 31 e
// 0x100 = 256; d) 16, 256 e 65.536 valores.

#include <stdio.h>

int main(void) {
    printf("%d\n", 0xFF);
    printf("%d %d\n", 0x1F, 0x100);
    return 0;
}
