// 0104 · BST: busca e inserção
// Exercício E620 · ★☆☆

#include <stdio.h>
#include "bst.h"

int menor_chave(const No *r) {
    while (r->esq != NULL) {
        r = r->esq; // nada à esquerda: é a menor
    }
    return r->chave;
}

int maior_chave(const No *r) {
    while (r->dir != NULL) {
        r = r->dir;
    }
    return r->chave;
}

int main(void) {
    int matriculas[] = {50, 30, 70, 20, 40, 60, 80};
    No *raiz = NULL;
    for (int i = 0; i < 7; i++) {
        raiz = bst_insere(raiz, matriculas[i]);
    }

    printf("Matrícula mais antiga: %d\n", menor_chave(raiz));
    printf("Matrícula mais nova: %d\n", maior_chave(raiz));

    raiz = bst_libera(raiz);
    return 0;
}
