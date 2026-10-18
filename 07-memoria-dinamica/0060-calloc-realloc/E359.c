// 0060 · calloc e realloc
// Exercício E359 · ★★★
//
// Compare duas estratégias de crescimento para guardar 1000 números, com
// capacidade inicial 1:
//
//   A) crescer de 1 em 1 (capacidade + 1) sempre que encher;
//   B) dobrar a capacidade sempre que encher.
//
// Escreva um programa que faça os dois vetores de verdade (com realloc) e
// conte, para cada estratégia, quantos realloc foram feitos e quantos
// elementos o realloc precisou copiar no pior caso (a quantidade guardada
// na hora de cada realloc).
//
//   Saída esperada:
//   +1:     999 realocações, 499500 cópias
//   dobrar: 10 realocações, 1023 cópias
//
// Dicas:
// 1. Escreva uma função que recebe um "modo" (1 ou 2) e devolve as contagens
//    por ponteiro (int *realocacoes, long *copias).
// 2. Antes de cada realloc, copias += quantidade.
// 3. Resposta esperada: a saída acima. No +1, as cópias são 1 + 2 + ... +
//    999 = 499500, um custo quadrático. Dobrando, 1 + 2 + 4 + ... + 512 =
//    1023: em média, nem uma cópia por elemento.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
