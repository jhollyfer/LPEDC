// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2714 · ★★☆ · Um processador de brinquedo
//
// Um processador de brinquedo tem instruções de 1 byte: os bits 7-6 são o
// código da operação (00 LOAD, 01 ADD, 10 SUB, 11 JMP) e os bits 5-0 são o
// operando (0 a 63). Escreva um programa que, com um switch, execute os bytes
// {0x05, 0x47, 0x83, 0xC0} sobre um acumulador que começa em 0, mostrando
// cada instrução decodificada.
//
//   Saída esperada:
//   0x05: LOAD 5 -> acc = 5
//   0x47: ADD 7 -> acc = 12
//   0x83: SUB 3 -> acc = 9
//   0xC0: JMP 0 (fim do programa)
//
// Dicas:
// 1. Código: (b >> 6) & 3u. Operando: b & 0x3Fu.
// 2. Um enum { LOAD, ADD, SUB, JMP } deixa os case legíveis: os valores 0 a
//    3 batem com os bits.
// 3. Guarde os bytes em unsigned char e mostre com 0x%02X.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
