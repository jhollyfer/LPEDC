// 0064 · Union
// Exercício E380 · ★☆☆
//
// Um float também é feito de 4 bytes, mas eles não guardam o número do jeito
// que um int guardaria. Crie uma union com um float e um uint32_t e mostre,
// em hexadecimal, os bits de 1.0, -2.0, 0.5 e 0.1.
//
//   Saída esperada:
//   1.0 -> 0x3F800000
//   -2.0 -> 0xC0000000
//   0.5 -> 0x3F000000
//   0.1 -> 0x3DCCCCCD
//
// Dicas:
// 1. typedef union { float f; uint32_t bits; } Espiao;
// 2. Grave em .f e leia em .bits. Mostre com 0x%08X e um cast para unsigned.
// 3. Repare: 1.0 não é 0x00000001. O float guarda sinal, expoente e mantissa
//    (padrão IEEE 754), e 0.1 nem tem representação exata: o CCCC repetido é
//    uma dízima em binário, e o D do fim é o arredondamento.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdint.h>
#include <stdio.h>

int main(void) {

    return 0;
}
