// 0003 · Tipos e limites
// Exercício E017 · ★★★
//
// Muitos sistemas guardam a hora como "segundos desde 1/1/1970" num inteiro
// de 32 bits com sinal. Esse contador estoura em 19/01/2038. Escreva um
// programa que mostre por quê: o maior int32_t, quantos segundos têm 68 e 69
// anos (de 365 dias) e o maior int64_t. Compare os números: 1970 + 68 =
// 2038, e o contador de 32 bits não aguenta chegar aos 69 anos.
//
//   Saída esperada:
//   int32_t vai até 2147483647
//   68 anos: 2144448000 segundos
//   69 anos: 2175984000 segundos
//   int64_t vai até 9223372036854775807
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdint.h>

int main(void) {

    return 0;
}
