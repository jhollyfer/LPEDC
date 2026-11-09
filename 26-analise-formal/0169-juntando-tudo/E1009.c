// 0169 · Juntando tudo: passos e bytes conferidos
// Exercício E1009 · ★☆☆
//
// Use o TAD custo.h desta pasta (o rodar compila o custo.c junto). Para
// n = 1000, 2000, 4000 e 8000, meça os passos de custo_soma e de
// custo_busca no pior caso (procure o valor 1, menor que todos os preços)
// e mostre ao lado a fórmula floor(log2 n) + 1 da busca:
//
//   Saída esperada:
//       n  soma  busca  log2(n)+1
//    1000  1000     10         10
//    2000  2000     11         11
//    4000  4000     12         12
//    8000  8000     13         13
//
// Dicas:
// 1. Preencha preco[i] = 50 + 2 * i (ordenado, para a busca binária).
// 2. Chame custo_zera() antes de cada medida e leia custo_passos depois.
// 3. floor e log2 estão em <math.h>. A soma dobra; a busca ganha 1.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <math.h>
#include "custo.h"

int main(void) {

    return 0;
}
