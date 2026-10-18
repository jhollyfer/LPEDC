// 0003 · Tipos e limites
// Exercício E013 · ★☆☆
//
// Converta na mão cada binário para hexadecimal (cada grupo de 4 bits vira
// um dígito hexa) e escreva os números no código SÓ em hexadecimal, com 0x
// na frente. Quem converte para decimal é o printf, com %d. Na tabela de
// quantos valores cabem, use também hexa: 2 elevado a 4 é 0x10.
//
//   binários: 0001 0110 e 1111 1111; hexas prontos: 0x1F e 0x100
//
//   Saída esperada:
//   0001 0110 = 0x16 = 22
//   1111 1111 = 0xFF = 255
//   0x1F = 31
//   0x100 = 256
//   4 bits: 16 valores
//   8 bits: 256 valores
//   16 bits: 65536 valores
//
// (Binário escrito como 0b10110 só virou padrão no C23; o rodar, que segue o
// C17, avisa se você usar.)
//
// Dicas:
// 1. 0001 é 1 e 0110 é 6: o primeiro binário é 0x16. 1111 é 15, o F.
// 2. printf("0001 0110 = 0x16 = %d\n", 0x16); o texto antes do %d é fixo.
// 3. Com n bits cabem 2 elevado a n valores: em binário é um 1 seguido de n
//    zeros, e cada 4 zeros viram um 0 no hexa: 0x10, 0x100 e 0x10000.
// 4. Resposta esperada: as sete linhas acima (16 + 4 + 2 = 22; 1 * 16 + 15
//    = 31).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
