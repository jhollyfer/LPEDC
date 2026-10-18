// A207 · As matrículas da academia

#include <stdio.h>
#include "bst.h"

// busca mostrando o caminho: em cada nó, uma comparação decide o lado
void procura(const No *r, int chave) {
    printf("Busca %d:", chave);
    while (r != NULL) {
        printf(" %d", r->chave);
        if (chave == r->chave) {
            printf(" -> achou\n");
            return;
        }
        r = chave < r->chave ? r->esq : r->dir;
    }
    printf(" -> NULL, não existe\n");
}

int main(void) {
    int matriculas[] = {50, 30, 70, 20, 40, 60, 80};
    No *raiz = NULL;
    for (int i = 0; i < 7; i++) {
        raiz = bst_insere(raiz, matriculas[i]);
    }

    printf("Em ordem:");
    bst_em_ordem(raiz);
    printf("\n");
    procura(raiz, 60);
    procura(raiz, 45);
    printf("Altura: %d\n", bst_altura(raiz));

    raiz = bst_libera(raiz);
    return 0;
}
// Saída:
// Em ordem: 20 30 40 50 60 70 80
// Busca 60: 50 70 60 -> achou
// Busca 45: 50 30 40 -> NULL, não existe
// Altura: 2
