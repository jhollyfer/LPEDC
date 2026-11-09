// 0176 · AVL: remoção
// Exercício E1052 · ★☆☆
//
// Escreva um fiscal para a AVL (avlrem.h): confere(r, lim_inf, lim_sup)
// devolve quantos nós a árvore tem se TODOS respeitarem três regras, e -1
// se algum falhar: (1) a chave está entre lim_inf e lim_sup (a ordem da
// BST), (2) o campo altura é 1 + o maior entre as alturas dos filhos, (3) o
// fator está em -1..1. Teste com a árvore das chaves 1 a 100 inseridas em
// ordem, da qual se removem os múltiplos de 3.
//
//   Saída esperada:
//   AVL ok: 67 nós, altura 6, 94 rotações no total
//
// Dicas:
// 1. Na chamada para a esquerda, o limite superior vira r->chave; para a
//    direita, o inferior. Comece com confere(raiz, -1, 1000) e use long nos
//    limites.
// 2. Para a altura, compare r->altura com avr_altura dos filhos.
// 3. Resposta esperada: a saída acima (as 94 rotações somam inserções e
//    remoções).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include "avlrem.h"

int main(void) {

    return 0;
}
