// 0124 · Juntando tudo
// Exercício E740 · ★☆☆
//
// Antes de ordenar, vale olhar os dados. Conte quantos dos 1 milhão de Pix
// do dia (pix_gera com a semente 2024) caem em cada faixa de valor: até
// R$ 9,99; de R$ 10 a R$ 99,99; de R$ 100 a R$ 999,99; R$ 1000 ou mais. É
// o primeiro laço do counting sort, com uma chave calculada: a faixa.
//
//   Saída esperada:
//   até R$ 9,99:         87654 ( 8.8%)
//   R$ 10 a R$ 99,99:   788605 (78.9%)
//   R$ 100 a R$ 999,99:  11383 ( 1.1%)
//   R$ 1000 ou mais:    112358 (11.2%)
//
// Dicas:
// 1. Escreva int faixa(int32_t centavos), que devolve 0, 1, 2 ou 3. Cuidado
//    com a unidade: R$ 9,99 são 999 centavos.
// 2. Um int c[4] = {0}; e c[faixa(v[i].centavos)]++ para cada Pix.
// 3. O vetor de 1 milhão de Pix (12 MB) vai no heap, com malloc e free.
// 4. Formato: "%s %6d (%4.1f%%)\n", com os rótulos já alinhados com espaços.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include "pix.h"

#define N 1000000

int main(void) {

    return 0;
}
