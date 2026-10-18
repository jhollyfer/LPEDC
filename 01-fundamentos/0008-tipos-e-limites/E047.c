// 0008 · Tipos e limites
// Exercício E047 · ★★★
//
// Dois estouros que viraram notícia:
//
// - Em 2014, o clipe "Gangnam Style" passou de 2.147.483.647 visualizações
//   e o YouTube teve de trocar o tipo do contador.
// - Muitos sistemas guardam a hora como "segundos desde 1/1/1970" num
//   inteiro de 32 bits com sinal. Esse contador estoura em 19/01/2038.
//
// Escreva um programa que mostre o maior int32_t e o maior int64_t, usando
// as constantes do stdint.h. Responda como comentário:
//
// a) Por que o número do YouTube é exatamente esse?
// b) Por que 2038? (um ano tem uns 31,5 milhões de segundos)
// c) Com int64_t, o problema some? Quantos anos cabem?
//
//   Saída esperada:
//   int32_t vai até 2147483647
//   int64_t vai até 9223372036854775807
//
// Dicas:
// 1. INT32_MAX e INT64_MAX. Para mostrar o de 64 bits, converta para long
//    long e use %lld: (long long)INT64_MAX.
// 2. 2147483647 é 2^31 - 1: 31 bits para o número e 1 para o sinal.
// 3. Resposta esperada: a) é o INT32_MAX, o maior int de 32 bits com sinal;
//    b) 2147483647 / 31,5 milhões dá uns 68 anos, e 1970 + 68 = 2038;
//    c) some na prática: 2^63 segundos são uns 292 bilhões de anos.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdint.h>

int main(void) {

    return 0;
}
