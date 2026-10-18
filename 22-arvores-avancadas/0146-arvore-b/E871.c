// 0146 · Árvore B
// Exercício E871 · ★☆☆
//
// Insira os códigos de 1 a 20, em ordem, numa árvore B (arvoreb.h, T = 2) e
// escreva duas funções recursivas: conta_chaves(r), o total de chaves, e
// conta_nos(r), o total de nós. Mostre a árvore com ab_mostra e a média de
// chaves por nó.
//
//   Saída esperada:
//     nível 0: [8]
//     nível 1: [4] [12]
//     nível 2: [2] [6] [10] [14 16 18]
//     nível 3: [1] [3] [5] [7] [9] [11] [13] [15] [17] [19 20]
//   chaves: 20 | nós: 17 | média: 1.18 chaves por nó
//
// Dicas:
// 1. Um nó com n chaves tem n + 1 filhos, de filho[0] a filho[n]. Folha não
//    tem filho nenhum: confira r->folha antes de descer.
// 2. conta_chaves começa com r->n; conta_nos começa com 1.
// 3. Resposta esperada: a saída acima. Repare como a inserção em ordem deixa
//    quase todo nó com uma chave só, de três possíveis.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "arvoreb.h"

int main(void) {

    return 0;
}
