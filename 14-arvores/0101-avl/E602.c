// 0101 · AVL: balanceamento e rotações
// Exercício E602 · ★☆☆
//
// O main insere os pedidos de 1 a 7, em ordem, numa AVL do TAD avl.h. Com 5
// e com 7 chaves ele mostra a pré-ordem e chama fatores(r), que você vai
// escrever: ela percorre a árvore em ordem e mostra cada chave com o fator
// de balanceamento dela entre parênteses (use avl_fator).
//
//   Saída esperada:
//   Com 5 chaves: pré 2 1 4 3 5
//     fatores: 1(0) 2(-1) 3(0) 4(0) 5(0)
//   Com 7 chaves: pré 4 2 1 3 6 5 7
//     fatores: 1(0) 2(0) 3(0) 4(0) 5(0) 6(0) 7(0)
//   Rotações: 4
//
// Dicas:
// 1. É uma em ordem: esquerda, o nó, direita. Árvore vazia não imprime nada.
// 2. Cada chave sai como printf(" %d(%d)", r->chave, avl_fator(r)).
// 3. Resposta esperada: a saída acima. Com 5 chaves a raiz 2 pende para a
//    direita (fator -1) e mesmo assim é AVL; com 7 a árvore fica perfeita.
//
// Escreva sua resposta abaixo (complete fatores):

#include <stdio.h>
#include "avl.h"

void fatores(const No *r) {
    (void)r; // apague esta linha quando escrever a função
}

int main(void) {
    No *raiz = NULL;
    for (int i = 1; i <= 7; i++) {
        raiz = avl_insere(raiz, i);
        if (i == 5 || i == 7) {
            printf("Com %d chaves: pré", i);
            avl_pre_ordem(raiz);
            printf("\n  fatores:");
            fatores(raiz);
            printf("\n");
        }
    }
    printf("Rotações: %d\n", avl_rotacoes());

    raiz = avl_libera(raiz);
    return 0;
}
