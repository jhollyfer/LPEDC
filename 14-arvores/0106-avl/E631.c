// 0106 · AVL: balanceamento e rotações
// Exercício E631 · ★☆☆
//
// Calcule, no papel, a altura e o fator de balanceamento (altura da esquerda
// menos altura da direita) de cada nó desta BST:
//
//   50
//   ├── esq: 30
//   │   ├── esq: 20
//   │   │   └── esq: 10
//   │   └── dir: 40
//   └── dir: 70
//       └── dir: 80
//           └── dir: 90
//
// Responda: (a) ela é uma AVL? (b) se não for, qual nó está desequilibrado e
// em qual dos quatro casos ele cai? (c) que rotação conserta, e como fica a
// árvore depois?
//
// Dicas:
// 1. Comece pelas folhas (altura 0) e suba. NULL tem altura -1.
// 2. O 70 não tem filho esquerdo: altura(esq) = -1.
// 3. Resposta esperada: fatores 50: 0, 30: +1, 20: +1, 10: 0, 40: 0,
//    70: -2, 80: -1, 90: 0. (a) não é AVL; (b) o 70, caso direita-direita;
//    (c) rotação à esquerda no 70: o 80 sobe com filhos 70 e 90, e a árvore
//    fica 50 (30 (20 (10), 40), 80 (70, 90)).
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>

int main(void) {

    return 0;
}
