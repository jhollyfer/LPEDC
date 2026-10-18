// 0100 · BST: remoção
// Exercício E595 · ★☆☆

#include <stdio.h>
#include "bst.h"

void pre(const No *r) {
    if (r == NULL) {
        return;
    }
    printf(" %d", r->chave);
    pre(r->esq);
    pre(r->dir);
}

// conta os filhos do nó: 0 é folha, 1 é um filho, 2 são dois
const char *caso(No *r, int chave) {
    No *n = bst_busca(r, chave);
    if (n == NULL) {
        return "não existe";
    }
    int filhos = (n->esq != NULL) + (n->dir != NULL);
    if (filhos == 0) {
        return "folha";
    }
    return filhos == 1 ? "um filho" : "dois filhos";
}

int main(void) {
    int chaves[] = {60, 25, 80, 10, 40, 70, 90, 35, 50};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = bst_insere(raiz, chaves[i]);
    }
    printf("%-24spré", "Antes:");
    pre(raiz);
    printf("\n");

    int sai[] = {10, 80, 25};
    char rotulo[32];
    for (int i = 0; i < 3; i++) {
        snprintf(rotulo, sizeof rotulo, "Sem o %d (%s):", sai[i], caso(raiz, sai[i]));
        raiz = bst_remove(raiz, sai[i]);
        printf("%-24spré", rotulo);
        pre(raiz);
        printf("\n");
    }
    raiz = bst_libera(raiz);
    return 0;
}
