// 0175 · Conceitos e sucessor
// Exercício E1045 · ★☆☆
//
// O estoque guarda os códigos 50, 30, 70, 20, 40, 60, 80, 35, 45 e 65,
// inseridos nessa ordem numa BST (arvpai.h). Escreva conta_graus(r, conta),
// que percorre a árvore e soma em conta[g] quantos nós têm grau g (0, 1 ou
// 2 filhos). Mostre as três contagens, o grau da árvore (o maior grau que
// aparece) e quantas folhas ela tem.
//
//   Saída esperada:
//   grau 0: 5 nós
//   grau 1: 1 nós
//   grau 2: 4 nós
//   grau da árvore: 2 | folhas: 5
//
// Dicas:
// 1. ap_grau(x) já devolve quantos filhos x tem. Faça conta[ap_grau(r)]++ e
//    chame para os dois filhos.
// 2. Folha é nó de grau 0. Numa árvore binária com n nós, n - 1 arestas:
//    some 0·5 + 1·1 + 2·4 e confira.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "arvpai.h"

int main(void) {

    return 0;
}
