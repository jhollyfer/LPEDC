// 0099 · BST: busca e inserção
// Exercício E592 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void insere_sem_recursao(No **raiz, int chave) {
    No **p = raiz; // endereço do ponteiro que estamos olhando
    while (*p != NULL) {
        if (chave == (*p)->chave) {
            return; // repetida
        }
        p = chave < (*p)->chave ? &(*p)->esq : &(*p)->dir;
    }
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->chave = chave;
    novo->esq = NULL;
    novo->dir = NULL;
    *p = novo; // muda a raiz ou o esq/dir de algum pai
}

int main(void) {
    int matriculas[] = {50, 30, 70, 20, 40, 60, 80, 30};
    No *raiz = NULL;
    for (int i = 0; i < 8; i++) {
        insere_sem_recursao(&raiz, matriculas[i]);
    }

    printf("Em ordem:");
    bst_em_ordem(raiz);
    printf("\nAltura: %d\n", bst_altura(raiz));

    raiz = bst_libera(raiz);
    return 0;
}
