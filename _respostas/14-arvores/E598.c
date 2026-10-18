// 0100 · BST: remoção
// Exercício E598 · ★★☆
//
// Resposta: a recursão removia "chave" (30) da subárvore direita, onde não
// existe 30. Nada saía e o 35 ficava duplicado. Nenhum nó foi liberado nem
// perdido, por isso o ASan não reclama. O certo é remover suc->chave.

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

No *remove_errado(No *r, int chave) {
    if (r == NULL) {
        return NULL;
    }
    if (chave < r->chave) {
        r->esq = remove_errado(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = remove_errado(r->dir, chave);
    } else if (r->esq == NULL || r->dir == NULL) {
        No *filho = r->esq != NULL ? r->esq : r->dir;
        free(r);
        return filho;
    } else {
        No *suc = r->dir;
        while (suc->esq != NULL) {
            suc = suc->esq;
        }
        r->chave = suc->chave;
        r->dir = remove_errado(r->dir, suc->chave); // remove o sucessor de baixo
    }
    return r;
}

int main(void) {
    int matriculas[] = {50, 30, 70, 20, 40, 60, 80, 35, 45};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = bst_insere(raiz, matriculas[i]);
    }
    raiz = remove_errado(raiz, 30);
    printf("Em ordem:");
    bst_em_ordem(raiz);
    printf("\n");

    raiz = bst_libera(raiz);
    return 0;
}
