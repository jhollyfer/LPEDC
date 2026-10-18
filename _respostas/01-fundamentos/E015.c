// 0003 · Tipos e limites
// Exercício E015 · ★★☆

#include <stdio.h>
#include <limits.h>

int main(void) {
    unsigned char brilho = 250;      // LED, de 0 a 255: some 10
    unsigned int estoque = 0;        // vendeu um que não tinha: tire 1
    unsigned short odometro = 65000; // painel de 16 bits: some 1000

    int antes = brilho;
    brilho = brilho + 10;            // 260 não cabe: 260 - 256 = 4
    printf("brilho: %d + 10 = %d (máximo %d)\n", antes, brilho, UCHAR_MAX);

    antes = estoque;
    estoque = estoque - 1;           // abaixo de zero: vai para o máximo
    printf("estoque: %d - 1 = %u (máximo %u)\n", antes, estoque, UINT_MAX);

    antes = odometro;
    odometro = odometro + 1000;      // 66000 - 65536 = 464
    printf("odômetro: %d + 1000 = %d (máximo %d)\n", antes, odometro, USHRT_MAX);
    return 0;
}
