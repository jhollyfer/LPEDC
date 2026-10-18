// 0054 · malloc e free
// Exercício E322 · ★★☆
//
// Escreva um programa que faça de verdade as cinco alocações abaixo. Antes
// de cada malloc, guarde numa variável size_t quantos bytes ele vai pedir
// (ex.: size_t ta = 5 * sizeof(int);) e passe essa variável para o malloc.
// Confira o NULL de cada uma, mostre os cinco tamanhos, mostre quantos int
// cabem inteiros no bloco e) e libere os cinco blocos no fim.
//
//   a) int *a = malloc(5 * sizeof(int));
//   b) double *b = malloc(5 * sizeof(double));
//   c) int **c = malloc(3 * sizeof(int *));
//   d) char *d = malloc(strlen("Recife") + 1);
//   e) int *e = malloc(5);
//
//   Saída esperada (num PC de 64 bits):
//   a) 20 bytes
//   b) 40 bytes
//   c) 24 bytes
//   d) 7 bytes
//   e) 5 bytes: cabe 1 int
//
// Dicas:
// 1. int tem 4 bytes, double 8 e qualquer ponteiro 8 (em 64 bits).
//    "Recife" tem 6 letras, mais o '\0'.
// 2. Se um malloc falhar, libere os que já deram certo antes de sair
//    (free(NULL) não faz nada, então dá para liberar todos de uma vez).
// 3. Resposta esperada: a saída acima. Em e) sobra 1 byte: escrever e[1]
//    ocuparia os bytes 4 a 7, fora do bloco. Acrescente e[1] = 9; para ver
//    o AddressSanitizer acusar heap-buffer-overflow, e depois apague a linha.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
