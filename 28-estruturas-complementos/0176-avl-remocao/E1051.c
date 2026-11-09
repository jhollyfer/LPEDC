// 0176 · AVL: remoção
// Exercício E1051 · ★☆☆
//
// A biblioteca guarda as matrículas dos leitores com livro emprestado numa
// AVL (avlrem.h). Insira 50, 25, 75, 10, 30, 60, 80, 5, 15, 27, 55 e 1, nessa
// ordem. Depois os leitores 80, 75 e 60 devolvem os livros: remova os três,
// um por vez, mostrando a pré-ordem, a altura e quantas rotações cada
// remoção fez (use avr_rotacoes antes e depois).
//
//   Saída esperada:
//   início:  pré 50 25 10 5 1 15 30 27 75 60 55 80 | altura 4
//   tira 80: pré 25 10 5 1 15 50 30 27 60 55 75 | altura 3 | rotações 2
//   tira 75: pré 25 10 5 1 15 50 30 27 60 55 | altura 3 | rotações 0
//   tira 60: pré 25 10 5 1 15 50 30 27 55 | altura 3 | rotações 0
//
// Dicas:
// 1. raiz = avr_remove(raiz, chave): a raiz pode mudar, guarde sempre o
//    retorno.
// 2. Desenhe a árvore antes de tirar o 80: o 75 fica pesado à esquerda e,
//    depois de consertado, o 50 também.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "avlrem.h"

int main(void) {

    return 0;
}
