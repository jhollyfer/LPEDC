// 0104 · BST: busca e inserção
// Exercício E624 · ★★★

#include <stdio.h>
#include "bst.h"

int main(void) {
    int rifa[] = {23, 8, 41, 15, 8, 30, 23, 4, 41, 12, 41};
    int n = sizeof(rifa) / sizeof(rifa[0]);
    No *raiz = NULL;
    int distintos = 0;

    for (int i = 0; i < n; i++) {
        if (bst_busca(raiz, rifa[i]) != NULL) {
            printf("Repetido: %d\n", rifa[i]);
        } else {
            raiz = bst_insere(raiz, rifa[i]);
            distintos++;
        }
    }

    printf("Distintos:");
    bst_em_ordem(raiz);
    printf("\nQuantos: %d\n", distintos);
    printf("Altura: %d\n", bst_altura(raiz));

    raiz = bst_libera(raiz);
    return 0;
}
