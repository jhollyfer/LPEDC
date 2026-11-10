// 0098 · Árvore binária e percursos
// Exercício E588 · ★★★
//
// Uma árvore binária cabe numa string: escreva a pré-ordem e marque cada
// subárvore vazia com um ponto. A árvore da expressão vira "*-8..3..+4..2.."
// e a árvore M, G, T, C, J, X do E583 vira "MGC..J..T.X..".
//
// Com o TAD arvore.h, escreva constroi(s, &pos), que lê a string a partir de
// s[pos] e devolve a árvore montada com arv_cria. Para cada string, mostre a
// em ordem, a pós-ordem, o número de nós e a altura.
//
//   Saída esperada:
//   *-8..3..+4..2..
//     em ordem:  8 - 3 * 4 + 2
//     pós-ordem: 8 3 - 4 2 + *
//     nós: 7, altura: 2
//   MGC..J..T.X..
//     em ordem:  C G J M T X
//     pós-ordem: C J G X T M
//     nós: 6, altura: 2
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "0098-arvore.h"

int main(void) {

    return 0;
}
