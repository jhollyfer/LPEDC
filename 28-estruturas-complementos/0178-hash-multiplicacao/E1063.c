// 0178 · Hash: divisão e multiplicação
// Exercício E1063 · ★☆☆
//
// A transportadora espalha os CEPs de entrega numa tabela de m = 97 baldes
// (97 é primo e fica longe de 64 e de 128). Use esp_divisao (espalha.h) para
// mostrar o balde de cada CEP: 69050000, 69020120, 69099999, 01310100,
// 20040002 e 69050097. Mostre o CEP com 8 dígitos (zeros à esquerda).
//
//   Saída esperada:
//        CEP | balde (m = 97)
//   69050000 | 65
//   69020120 | 61
//   69099999 | 12
//   01310100 | 18
//   20040002 | 93
//   69050097 | 65
//
// Dicas:
// 1. Guarde os CEPs num vetor de uint32_t. Atenção: 01310100 escrito assim
//    em C é octal! Escreva 1310100 e mostre com %08u.
// 2. Repare no 69050000 e no 69050097: diferem por 97, caem no mesmo balde.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "espalha.h"

int main(void) {

    return 0;
}
