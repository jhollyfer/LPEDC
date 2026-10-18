// 0103 · Árvore binária e percursos
// Exercício E614 · ★☆☆

#include <stdio.h>
#include "arvore.h"

int conta_folhas(const No *r) {
    if (r == NULL) {
        return 0;
    }
    if (r->esq == NULL && r->dir == NULL) {
        return 1;
    }
    return conta_folhas(r->esq) + conta_folhas(r->dir);
}

int conta_internos(const No *r) {
    if (r == NULL || (r->esq == NULL && r->dir == NULL)) {
        return 0; // vazia ou folha
    }
    return 1 + conta_internos(r->esq) + conta_internos(r->dir);
}

int main(void) {
    No *raiz = arv_cria('*',
                        arv_cria('-', arv_cria('8', NULL, NULL), arv_cria('3', NULL, NULL)),
                        arv_cria('+', arv_cria('4', NULL, NULL), arv_cria('2', NULL, NULL)));

    printf("Números: %d\n", conta_folhas(raiz));
    printf("Operadores: %d\n", conta_internos(raiz));

    raiz = arv_libera(raiz);
    return 0;
}
