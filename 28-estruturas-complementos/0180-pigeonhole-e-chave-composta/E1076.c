// 0180 · Pigeonhole e chave composta
// Exercício E1076 · ★☆☆
//
// O folheto do mercado lista os produtos pelo preço e, no empate de preço,
// pelo nome. Escreva o comparador composto para o qsort e ordene: sabao
// 8.99, arroz 25.90, cafe 18.90, acucar 8.99, feijao 8.99, oleo 7.90 e leite
// 5.90 (guarde os preços em centavos).
//
//   Saída esperada:
//   leite   R$  5.90
//   oleo    R$  7.90
//   acucar  R$  8.99
//   feijao  R$  8.99
//   sabao   R$  8.99
//   cafe    R$ 18.90
//   arroz   R$ 25.90
//
// Dicas:
// 1. int compara(const void *a, const void *b): converta para
//    const Produto * e compare o preço primeiro; se empatar, strcmp nos
//    nomes.
// 2. Devolva negativo, zero ou positivo. Para o preço, (x < y ? -1 : 1).
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
