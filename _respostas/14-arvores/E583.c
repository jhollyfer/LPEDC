// 0098 · Árvore binária e percursos
// Exercício E583 · ★☆☆

#include <stdio.h>
#include "arvore.h"

int main(void) {
    // de baixo para cima: primeiro as folhas, depois quem aponta para elas
    No *g = arv_cria('G', arv_cria('C', NULL, NULL), arv_cria('J', NULL, NULL));
    No *t = arv_cria('T', NULL, arv_cria('X', NULL, NULL)); // sem filho esquerdo
    No *raiz = arv_cria('M', g, t);

    printf("Pré-ordem:");
    arv_pre_ordem(raiz);
    printf("\nEm ordem: ");
    arv_em_ordem(raiz);
    printf("\nPós-ordem:");
    arv_pos_ordem(raiz);
    printf("\nPor nível:");
    arv_por_nivel(raiz);
    printf("\nNós: %d, altura: %d\n", arv_conta(raiz), arv_altura(raiz));

    raiz = arv_libera(raiz);
    return 0;
}
