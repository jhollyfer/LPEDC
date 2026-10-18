// 0070 · Bits, máscaras e flags
// Exercício E415 · ★☆☆
//
// Faça à mão, em binário, com a = 0xCA e b = 0x5C (dois unsigned char).
// Dê cada resultado em binário, hexa e decimal. Depois confira com printf.
//
//   a) a & b
//   b) a | b
//   c) a ^ b
//   d) ~a      (guardado num unsigned char)
//   e) a << 1  (guardado num unsigned char)
//   f) a >> 3
//
// Dicas:
// 1. Primeiro passe para binário: cada dígito hexa vira 4 bits.
//    C = 1100, A = 1010, 5 = 0101.
// 2. Escreva um embaixo do outro e aplique a regra casa por casa.
// 3. Guardado num unsigned char, só sobram os 8 bits de baixo:
//    unsigned char r = ~a; e mostre com %02X.
// 4. Resposta esperada: a = 1100 1010 (202), b = 0101 1100 (92).
//    a) 0100 1000 = 0x48 = 72; b) 1101 1110 = 0xDE = 222;
//    c) 1001 0110 = 0x96 = 150; d) 0011 0101 = 0x35 = 53;
//    e) 1001 0100 = 0x94 = 148 (o 1 da esquerda caiu fora);
//    f) 0001 1001 = 0x19 = 25 (202 / 8 = 25, divisão inteira).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
