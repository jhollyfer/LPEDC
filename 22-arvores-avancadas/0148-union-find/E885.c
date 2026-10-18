// 0148 · Union-find
// Exercício E885 · ★★☆
//
// O técnico ligou os 7 computadores do escritório (0 a 6) com 9 cabos, na
// ordem do vetor. Um cabo é redundante quando liga dois computadores que JÁ
// conversavam por outros cabos (ele fecha um ciclo). Com o TAD (uniao.h),
// mostre cada cabo redundante, quantos cabos bastariam e se a rede ficou toda
// ligada.
//
//   Saída esperada:
//   cabo 4 (2-0) é redundante
//   cabo 8 (6-3) é redundante
//   cabo 9 (2-5) é redundante
//   3 cabos redundantes; 6 cabos bastam; rede toda ligada
//
// Dicas:
// 1. uf_une devolve false quando os dois já estavam no mesmo grupo. É
//    exatamente o teste do cabo redundante.
// 2. Os cabos são numerados a partir de 1 na saída (i + 1).
// 3. Resposta esperada: a saída acima. Com 7 computadores, 6 cabos sem ciclo
//    ligam tudo: é uma árvore. A mesma ideia vai aparecer no algoritmo de
//    Kruskal, no módulo 23.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "uniao.h"

int main(void) {
    // cabos do escritório: cada par liga dois computadores (0 a 6)
    int cabos[][2] = {{0, 1}, {1, 2}, {3, 4}, {2, 0}, {4, 5}, {5, 6}, {1, 4}, {6, 3}, {2, 5}};
    int n = 9;
    (void)cabos; // apague estas duas linhas
    (void)n;

    return 0;
}
