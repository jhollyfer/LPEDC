// 0059 · malloc e free
// Exercício E352 · ★★☆
//
// Quantos bytes cada chamada pede? Responda antes de rodar, supondo um PC de
// 64 bits. Depois escreva um programa que mostre os cinco números com sizeof
// e strlen, para conferir.
//
//   a) int *a = malloc(5 * sizeof(int));
//   b) double *b = malloc(5 * sizeof(double));
//   c) int **c = malloc(3 * sizeof(int *));
//   d) char *d = malloc(strlen("Recife") + 1);
//   e) int *e = malloc(5);
//
// Em e), quantos int cabem de verdade? O que acontece em e[1] = 9; ?
//
// Dicas:
// 1. int tem 4 bytes, double 8 e qualquer ponteiro 8 (em 64 bits).
// 2. "Recife" tem 6 letras, mais o '\0'.
// 3. Resposta esperada: a) 20; b) 40; c) 24; d) 7; e) 5 bytes: cabe só um
//    int (sobra 1 byte). e[1] ocupa os bytes 4 a 7: escreve fora do bloco, e
//    o AddressSanitizer acusa heap-buffer-overflow.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
