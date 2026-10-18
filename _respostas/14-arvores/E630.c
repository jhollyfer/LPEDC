// 0105 · BST: remoção
// Exercício E630 · ★★★
//
// Resposta: o 30 tem dois filhos; o bst_remove copiou a chave do sucessor
// (35) para o nó do 30 e deu free no nó original do 35, que era o que
// "ficha" guardava. Depois de mudar a árvore, busque o nó de novo.

#include <stdio.h>
#include "bst.h"

int main(void) {
    int matriculas[] = {50, 30, 70, 20, 40, 60, 80, 35, 45};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = bst_insere(raiz, matriculas[i]);
    }

    No *ficha = bst_busca(raiz, 35);
    printf("Ficha guardada: %d\n", ficha->chave);

    raiz = bst_remove(raiz, 30);
    ficha = bst_busca(raiz, 35); // o nó antigo do 35 foi liberado: busque de novo
    printf("Ficha depois de remover o 30: %d\n", ficha->chave);

    raiz = bst_libera(raiz);
    return 0;
}
