// 0100 · BST: remoção
// Exercício E599 · ★★★

#include <stdio.h>
#include "bst.h"

No *remove_faixa(No *r, int a, int b) {
    if (r == NULL) {
        return NULL;
    }
    r->esq = remove_faixa(r->esq, a, b); // limpa as subárvores primeiro
    r->dir = remove_faixa(r->dir, a, b);
    if (r->chave >= a && r->chave <= b) {
        r = bst_remove(r, r->chave);
    }
    return r;
}

int main(void) {
    int matriculas[] = {50, 30, 70, 20, 40, 60, 80, 35, 45};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = bst_insere(raiz, matriculas[i]);
    }
    printf("Antes: ");
    bst_em_ordem(raiz);
    raiz = remove_faixa(raiz, 35, 65);
    printf("\nDepois:");
    bst_em_ordem(raiz);
    printf("\nRaiz: %d, altura: %d\n", raiz->chave, bst_altura(raiz));

    raiz = bst_libera(raiz);
    return 0;
}
