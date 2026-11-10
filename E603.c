// 0101 · AVL: balanceamento e rotações
// Exercício E603 · ★★☆
//
// Use o struct Arv do E601 (chave, esq, dir, sem campo de altura). Escreva
// altura_se_avl(r): devolve a altura da árvore se ela respeitar a regra da
// AVL em todos os nós, ou -2 se algum nó tiver fator fora de -1..1. Visite
// cada nó UMA vez só. Teste duas árvores:
//
//   Árvore 1: a do E601.
//   Árvore 2: a mesma, mas com a subárvore direita da raiz trocada por
//             80 (filhos 70 e 90).
//
//   Saída esperada:
//   Árvore 1: não é AVL
//   Árvore 2: é AVL, altura 3
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct Arv {
    int chave;
    struct Arv *esq, *dir;
} Arv;

int main(void) {

    return 0;
}
