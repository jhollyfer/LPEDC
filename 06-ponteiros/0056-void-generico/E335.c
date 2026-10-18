// 0056 · void * e cast
// Exercício E335 · ★★★
//
// Escreva uma busca linear genérica:
//
//   int busca(const void *v, size_t n, size_t tam, const void *alvo,
//             int (*igual)(const void *, const void *))
//
// que devolve o índice do primeiro elemento igual ao alvo (segundo a função
// igual) ou -1. Use com três vetores:
//
//   int cods[5] = {310, 422, 518, 422, 907};          alvo 422
//   double precos[4] = {9.90, 15.50, 4.25, 30.00};    alvo 4.25
//   const char *nomes[3] = {"ana", "bia", "caio"};    alvo "caio"
//
//   Saída esperada:
//   422 no índice 1
//   4.25 no índice 2
//   caio no índice 2
//   bruno no índice -1
//
// Dicas:
// 1. O endereço do i-ésimo: (const unsigned char *)v + i * tam.
// 2. Para as strings, cada elemento é um const char *: a função igual
//    recebe endereços de const char * e usa strcmp.
// 3. Resposta esperada: índices 1, 2, 2 e -1 (bruno não está).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
