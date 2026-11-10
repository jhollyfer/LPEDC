// A342 · Promoção, conversão e deslocamento

#include <stdio.h>

int main(void) {
    // promoção inteira: o byte vira int antes do ~
    unsigned char x = 0x0F; // 0000 1111
    printf("~x = %d\n", ~x);                          // ~15 em int
    printf("(unsigned char)~x = %d\n", (unsigned char)~x); // de volta a 1 byte
    printf("sizeof x = %zu, sizeof(x + x) = %zu\n", sizeof x, sizeof(x + x));

    // conversão aritmética usual
    int i = -1;
    unsigned u = 1u;
    printf("i + u = %u\n", i + u);  // i vira unsigned: 4294967295 + 1 dá a volta
    printf("i - u = %u\n", i - u);  // seria -2, mas o resultado é unsigned
    long l = -1;                    // long de 64 bits cabe todo unsigned
    printf("l - u = %ld\n", l - u); // aqui o u vira long, e o -2 sobrevive

    // deslocamento à direita: divide por 2 a cada casa, mas arredonda diferente
    int queda = -17;
    // (o >> de um negativo depende do compilador; o gcc copia o bit de sinal)
    printf("-17 / 4 = %d, -17 >> 2 = %d\n", queda / 4, queda >> 2);
    unsigned positivo = 17u;
    printf(" 17 / 4 = %u,  17 >> 2 = %u\n", positivo / 4, positivo >> 2);

    // máscara: o cartão guarda o mês da validade nos 4 bits de baixo
    // e o ano (desde 2000) nos bits de cima
    unsigned validade = (31u << 4) | 9u; // 09/2031
    printf("validade: %02u/%u\n", validade & 0xFu, 2000u + (validade >> 4));
    return 0;
}
// Saída:
// ~x = -16
// (unsigned char)~x = 240
// sizeof x = 1, sizeof(x + x) = 4
// i + u = 0
// i - u = 4294967294
// l - u = -2
// -17 / 4 = -4, -17 >> 2 = -5
//  17 / 4 = 4,  17 >> 2 = 4
// validade: 09/2031
