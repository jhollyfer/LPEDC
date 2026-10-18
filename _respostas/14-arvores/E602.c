// 0101 · AVL: balanceamento e rotações
// Exercício E602 · ★☆☆

#include <stdio.h>
#include "avl.h"

// em ordem, cada chave com o fator dela entre parênteses
void fatores(const No *r) {
    if (r == NULL) {
        return;
    }
    fatores(r->esq);
    printf(" %d(%d)", r->chave, avl_fator(r));
    fatores(r->dir);
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
