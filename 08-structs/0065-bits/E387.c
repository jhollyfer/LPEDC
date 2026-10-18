// 0065 · Bits, máscaras e flags
// Exercício E387 · ★★☆
//
// Escreva duas funções para um uint16_t (16 bits):
//
//   - void mostrar_bits(uint16_t x): mostra os 16 bits, do 15 ao 0, com um
//     espaço a cada 4;
//   - int contar_uns(uint16_t x): conta quantos bits estão ligados.
//
// Use as duas em 2025, 255 e 4096 e diga a paridade (par ou ímpar) da
// quantidade de bits 1. Esse "bit de paridade" é um jeito antigo e barato de
// detectar um bit corrompido numa transmissão.
//
//   Saída esperada:
//   2025: 0000 0111 1110 1001 -> 8 bits 1 (par)
//   255: 0000 0000 1111 1111 -> 8 bits 1 (par)
//   4096: 0001 0000 0000 0000 -> 1 bits 1 (ímpar)
//
// Dicas:
// 1. Para o bit b: (x >> b) & 1u. Percorra b de 15 até 0.
// 2. Espaço a cada 4: quando b % 4 == 0 e b > 0.
// 3. Contar: some o bit 0 e desloque x uma casa para a direita até x
//    zerar.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdint.h>
#include <stdio.h>

int main(void) {

    return 0;
}
