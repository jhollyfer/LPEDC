// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2820 · ★★☆ · Múltiplos de 32 na tabela
//
// Os lotes do almoxarifado têm números múltiplos de 32: 32, 64, ..., 3200
// (100 lotes). Compare, numa tabela de m = 32 baldes, a divisão k mod 32 e a
// multiplicação em inteiros (k * 2654435769u) >> 27, com uint32_t. Mostre
// para cada uma quantos baldes ficaram vazios e o tamanho do balde mais
// cheio. Depois repita a divisão com m = 31.
//
//   Saída esperada:
//   vazios 31 | mais cheio 100 | divisão, m = 32
//   vazios  5 | mais cheio   5 | multiplicação, m = 32
//   vazios  0 | mais cheio   4 | divisão, m = 31
//
// Dicas:
// 1. m = 32 = 2^5: a multiplicação pega os 5 bits mais altos do produto (>>
//    27).
// 2. k mod 32 só olha os 5 bits de baixo de k, que são todos zero.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdint.h>
#include <stdio.h>

int main(void) {

    return 0;
}
