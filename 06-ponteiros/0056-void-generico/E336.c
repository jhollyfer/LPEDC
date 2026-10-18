// 0056 · void * e cast
// Exercício E336 · ★★★
//
// Usando a função mostra_bytes do A112, preveja SEM rodar o que aparece
// para cada variável, num PC little-endian:
//
//   short curto = 258;
//   unsigned int cor = 0x0A0B0C0D;
//   int negativo = -2;
//   char sigla[] = "BR";
//
// Depois rode e confira.
//
// Dicas:
// 1. Escreva cada número em hexa com todos os bytes (short tem 2, int 4) e
//    inverta a ordem dos bytes.
// 2. -2 em complemento de dois é 0xFFFFFFFE. 'B' é 0x42 e 'R' é 0x52.
// 3. Resposta esperada:
//    curto: 02 01 (258 = 0x0102)
//    cor: 0d 0c 0b 0a
//    negativo: fe ff ff ff
//    sigla: 42 52 00
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
