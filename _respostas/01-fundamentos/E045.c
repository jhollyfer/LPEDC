// 0008 · Tipos e limites
// Exercício E045 · ★★☆
//
// Resposta: 4 (250 + 10 = 260, menos 256), 4294967295 (0 - 1 dá a volta
// para o maior unsigned int) e 464 (65000 + 1000 = 66000, menos 65536).

#include <stdio.h>

int main(void) {
    unsigned char brilho = 250;
    brilho = brilho + 10;
    printf("%d\n", brilho);

    unsigned int estoque = 0;
    estoque = estoque - 1;
    printf("%u\n", estoque);

    unsigned short odometro = 65000;
    odometro = odometro + 1000;
    printf("%d\n", odometro);
    return 0;
}
