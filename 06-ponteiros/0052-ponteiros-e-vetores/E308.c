// 0052 · Ponteiros e vetores
// Exercício E308 · ★☆☆
//
// Preveja cada valor SEM rodar. O vetor v começa no endereço (fictício)
// 0x2000 e cada int tem 4 bytes.
//
//   int v[6] = {10, 20, 30, 40, 50, 60};
//   int *p = v + 1;
//
//   a) *p          b) *(p + 3)      c) *p + 3
//   d) p[2]        e) *(v + 5)      f) o endereço p + 3
//
//   Depois de p += 2:
//   g) *p          h) p[-1]         i) p - v
//
// Escreva o programa e mostre cada item para conferir (o endereço do item
// f vai sair diferente; confira só que fica 12 bytes depois de p).
//
// Dicas:
// 1. p começa em v[1]. p[k] é *(p + k), contado a partir de onde p está.
// 2. Em *p + 3, o * vem primeiro.
// 3. Resposta esperada: a) 20; b) 50; c) 23; d) 40; e) 60; f) 0x2010;
//    g) 40; h) 30; i) 3.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
