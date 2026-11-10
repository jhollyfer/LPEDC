// 0153 · Prim: a árvore que cresce
// Exercício E913 · ★☆☆
//
// Na orla, um gerador vai alimentar quatro quiosques: Coco, Pastel, Açaí e
// Milho. A matriz tem os metros de cabo de cada trecho possível (0 quer dizer
// "não dá para passar cabo"):
//
//               Gerador  Coco  Pastel  Açaí  Milho
//   Gerador        0      12     20     25     0
//   Coco          12       0      9      0    30
//   Pastel        20       9      0      6    15
//   Açaí          25       0      6      0    11
//   Milho          0      30     15     11     0
//
// Escreva o Prim sem heap, em O(V²), a partir do Gerador: vetores chave[],
// pai[] e na_rede[]; a cada passo, entra o vértice fora da rede com a menor
// chave. Mostre cada cabo na ordem em que entra e o total.
//
//   Saída esperada:
//   Gerador - Coco: 12 m
//   Coco - Pastel: 9 m
//   Pastel - Açaí: 6 m
//   Açaí - Milho: 11 m
//   Total: 38 m
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define INFINITO INT_MAX

int main(void) {

    return 0;
}
