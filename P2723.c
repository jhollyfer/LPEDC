// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2723 · ★★★ · O sensor que manda bytes
//
// Um sensor de temperatura manda cada leitura num byte em complemento de
// dois (-128 a 127), e um segundo sensor manda leituras de 12 bits. Sem
// depender de conversão "definida pela implementação", escreva:
//
//   int de_byte(uint8_t b)       // 0x80 a 0xFF são negativos
//   uint8_t para_byte(int v)     // o caminho de volta, de -128 a 127
//   int de_12_bits(unsigned x)   // estende o sinal: o bit 11 é o sinal
//
// Converta os bytes {0x00, 0x7F, 0x80, 0xFF, 0xF6}, volte o -10 para byte e
// leia os valores de 12 bits 0x7FF e 0xFF6.
//
//   Saída esperada:
//   0x00 -> 0
//   0x7F -> 127
//   0x80 -> -128
//   0xFF -> -1
//   0xF6 -> -10
//   -10 -> 0xF6
//   12 bits: 0x7FF -> 2047, 0xFF6 -> -10
//
// Dicas:
// 1. Se b >= 128, o valor é b - 256. Isso é conta com int: sempre definida.
// 2. Converter para unsigned é sempre definido: (uint8_t)v soma 256 aos
//    negativos.
// 3. Com 12 bits, a régua é 4096: se o bit 11 (0x800) está ligado, o valor é
//    x - 4096.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdint.h>
#include <stdio.h>

int main(void) {

    return 0;
}
