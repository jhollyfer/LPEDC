// 0100 · BST: remoção
// Exercício E598 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// remove o menor nó (o mais à esquerda); guarda a chave em *menor
No *remove_menor(No *r, int *menor) {
    if (r->esq == NULL) {
        No *dir = r->dir;
        *menor = r->chave;
        free(r);
        return dir;
    }
    r->esq = remove_menor(r->esq, menor);
    return r;
}

int main(void) {
    int matriculas[] = {50, 30, 70, 20, 40, 60, 80, 35, 45};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = bst_insere(raiz, matriculas[i]);
    }

    int chamada = 0;
    while (raiz != NULL) {
        int menor;
        raiz = remove_menor(raiz, &menor);
        chamada++;
        printf("Chamada %d: matrícula %d\n", chamada, menor);
    }
    printf("Árvore vazia: %s\n", raiz == NULL ? "sim" : "não");
    return 0;
}
