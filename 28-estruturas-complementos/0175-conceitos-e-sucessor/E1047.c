// 0175 · Conceitos e sucessor
// Exercício E1047 · ★★☆
//
// A loja de calçados guarda os preços (em centavos) numa BST com pai
// (arvpai.h): 1890, 990, 2450, 1290, 3100, 750 e 2100, nessa ordem. Mostre os
// preços do mais caro ao mais barato SEM recursão: comece no ap_maximo e
// ande com ap_antecessor até chegar em NULL. Depois mostre os vizinhos do
// preço 12.90 (o antecessor e o sucessor dele).
//
//   Saída esperada:
//   Do mais caro ao mais barato: 31.00 24.50 21.00 18.90 12.90 9.90 7.50
//   Vizinhos de 12.90: 9.90 e 18.90
//
// Dicas:
// 1. for (NoP *x = ap_maximo(raiz); x != NULL; x = ap_antecessor(x)).
// 2. Para os vizinhos, primeiro ap_busca(raiz, 1290).
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "arvpai.h"

int main(void) {

    return 0;
}
