// 0004 · Constantes
// Exercício E022 · ★★☆
//
// O jeito de escrever um literal decide o tipo e, às vezes, o valor. Escreva
// um programa que mostre, para cada literal abaixo, o valor (com %d para os
// inteiros e %.1f para os reais) e o tamanho (sizeof, com %zu). O "0" é
// texto: dele, mostre só o tamanho.
//
//   10     10.0     10.0f     010     0x10     '0'     "0"     1e3
//
//   Saída esperada:
//   10: vale 10, 4 bytes
//   10.0: vale 10.0, 8 bytes
//   10.0f: vale 10.0, 4 bytes
//   010: vale 8, 4 bytes
//   0x10: vale 16, 4 bytes
//   '0': vale 48, 4 bytes
//   "0": 2 bytes
//   1e3: vale 1000.0, 8 bytes
//
// Dicas:
// 1. Sem ponto é int; com ponto é double; o sufixo f faz float.
// 2. Zero à esquerda é octal; 0x é hexadecimal; aspas simples dão o código
//    do caractere (um int); aspas duplas são texto com o byte zero no fim.
// 3. Para mostrar aspas e apóstrofo no formato: \" e '.
// 4. Resposta esperada: as oito linhas acima. Ex.:
//    printf("010: vale %d, %zu bytes\n", 010, sizeof 010);
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
