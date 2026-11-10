// 0176 · AVL: remoção
// Exercício E1056 · ★★★
//
// Na inserção, a AVL faz no máximo uma rotação (simples ou dupla). Na
// remoção, não: o conserto pode subir até a raiz. O pior caso é a árvore de
// Fibonacci de altura h: a esquerda é uma árvore de Fibonacci de altura h - 1
// e a direita, de altura h - 2 (todo nó tem fator 1). Escreva
// fibonacci(h), que monta essa árvore direto com malloc (NoA de avlrem.h,
// campo altura preenchido, chaves 1, 2, 3... em ordem), e, para h de 2 a 9,
// remova a MAIOR chave com avr_remove e mostre quantos nós havia, quantas
// rotações a remoção fez e a altura depois.
//
//   Saída esperada:
//   altura 2:   4 nós | rotações 1 | altura depois 1
//   altura 3:   7 nós | rotações 1 | altura depois 2
//   altura 4:  12 nós | rotações 2 | altura depois 3
//   altura 5:  20 nós | rotações 2 | altura depois 4
//   altura 6:  33 nós | rotações 3 | altura depois 5
//   altura 7:  54 nós | rotações 3 | altura depois 6
//   altura 8:  88 nós | rotações 4 | altura depois 7
//   altura 9: 143 nós | rotações 4 | altura depois 8
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include "avlrem.h"

int main(void) {

    return 0;
}
