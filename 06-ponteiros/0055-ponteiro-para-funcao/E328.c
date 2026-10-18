// 0055 · Ponteiro para função
// Exercício E328 · ★★☆
//
// Ordene as frutas da barraca em ordem alfabética com qsort:
//
//   const char *frutas[] = {"manga", "abacaxi", "caju", "banana", "acerola"};
//
//   Saída esperada:
//   abacaxi acerola banana caju manga
//
// O detalhe: cada elemento do vetor é um const char *. O qsort entrega à
// comparação o ENDEREÇO de um elemento, ou seja, o endereço de um
// const char * (um ponteiro para ponteiro, assunto 0054).
//
// Dicas:
// 1. Dentro da comparação: const char *x = *(const char * const *)a;
// 2. Depois é só return strcmp(x, y);
// 3. O tamanho de cada elemento é sizeof frutas[0] (8 bytes: um ponteiro).
// 4. Resposta esperada: abacaxi acerola banana caju manga.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
