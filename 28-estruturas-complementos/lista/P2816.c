// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2816 · ★★☆ · Escreva a remoção da AVL
//
// Escreva, do zero, uma AVL com inserção e remoção (nó com altura guardada,
// rotações à esquerda e à direita e um equilibra que serve para as duas
// operações; na remoção de nó com dois filhos, use o sucessor). Conte as
// rotações simples num contador global (a dupla conta 2). Insira 30, 20, 40,
// 10, 25, 35, 50, 5, 15, 45, 1 e remova 35, 40 e 25, mostrando a pré-ordem,
// a altura e as rotações de cada remoção.
//
//   Saída esperada:
//   início: pré 30 10 5 1 20 15 25 40 35 50 45 | altura 3
//   tira 35: pré 30 10 5 1 20 15 25 45 40 50 | altura 3 | rotações 2
//   tira 40: pré 30 10 5 1 20 15 25 45 50 | altura 3 | rotações 0
//   tira 25: pré 30 10 5 1 20 15 45 50 | altura 3 | rotações 0
//
// Dicas:
// 1. O equilibra recalcula a altura, olha o fator e escolhe simples ou
//    dupla: na remoção, filho com fator 0 pede a simples.
// 2. raiz = remove_chave(raiz, k): a raiz pode mudar.
// 3. Tirar o 35 deixa o 40 pesado à direita, com o filho 50 pendendo para
//    dentro (fator 1): rotação dupla.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
