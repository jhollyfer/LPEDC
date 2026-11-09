// 0169 · Juntando tudo: passos e bytes conferidos
// Exercício E1011 · ★★☆
//
// Confira a ficha de ESPAÇO do merge sort do custo.h. Para n = 1000, 2000,
// 4000 e 8000, ordene um vetor ao contrário com custo_merge e mostre os
// bytes pedidos ao malloc ao lado de 4n (sizeof(int) = 4) e a
// profundidade máxima (custo_prof_max) ao lado de teto(log2 n) + 2:
//
//   Saída esperada:
//       n  bytes   4n  frames  teto(log2 n)+2
//    1000   4000  4000      12              12
//    2000   8000  8000      13              13
//    4000  16000 16000      14              14
//    8000  32000 32000      15              15
//
// Dicas:
// 1. custo_bytes é size_t: mostre com %zu.
// 2. Os frames são: o custo_merge (1), mais a recursão do ordena, que
//    desce até pedaços de 1 elemento: teto(log2 n) + 1 níveis.
// 3. O espaço extra total é Θ(n) + Θ(log n) = Θ(n): o vetor auxiliar domina.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <math.h>
#include "custo.h"

int main(void) {

    return 0;
}
