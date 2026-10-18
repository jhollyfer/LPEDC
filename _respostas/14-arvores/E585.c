// 0098 · Árvore binária e percursos
// Exercício E585 · ★★☆

#include <stdio.h>
#include "arvore.h"

void espelha(No *r) {
    if (r == NULL) {
        return;
    }
    No *aux = r->esq;
    r->esq = r->dir;
    r->dir = aux;
    espelha(r->esq);
    espelha(r->dir);
}

int main(void) {
    No *raiz = arv_cria('*',
                        arv_cria('-', arv_cria('8', NULL, NULL), arv_cria('3', NULL, NULL)),
                        arv_cria('+', arv_cria('4', NULL, NULL), arv_cria('2', NULL, NULL)));

    printf("Antes: ");
    arv_em_ordem(raiz);
    espelha(raiz);
    printf("\nDepois:");
    arv_em_ordem(raiz);
    printf("\n");

    raiz = arv_libera(raiz);
    return 0;
}
