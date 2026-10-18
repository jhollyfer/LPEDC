// 0100 · BST: remoção
// Exercício E597 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void pre(const No *r) {
    if (r == NULL) {
        return;
    }
    printf(" %d", r->chave);
    pre(r->esq);
    pre(r->dir);
}

No *remove_antecessor(No *r, int chave) {
    if (r == NULL) {
        return NULL;
    }
    if (chave < r->chave) {
        r->esq = remove_antecessor(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = remove_antecessor(r->dir, chave);
    } else if (r->esq == NULL || r->dir == NULL) {
        No *filho = r->esq != NULL ? r->esq : r->dir;
        free(r);
        return filho;
    } else {
        No *ant = r->esq; // uma vez à esquerda...
        while (ant->dir != NULL) {
            ant = ant->dir; // ...e à direita até o fim
        }
        r->chave = ant->chave;
        r->esq = remove_antecessor(r->esq, ant->chave);
    }
    return r;
}

int main(void) {
    int matriculas[] = {50, 30, 70, 20, 40, 60, 80, 35, 45};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = bst_insere(raiz, matriculas[i]);
    }
    printf("Antes:     pré");
    pre(raiz);
    raiz = remove_antecessor(raiz, 30);
    printf("\nSem o 30:  pré");
    pre(raiz);
    raiz = remove_antecessor(raiz, 50);
    printf("\nSem o 50:  pré");
    pre(raiz);
    printf("\n");

    raiz = bst_libera(raiz);
    return 0;
}
