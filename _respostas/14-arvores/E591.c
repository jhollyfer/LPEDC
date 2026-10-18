// 0099 · BST: busca e inserção
// Exercício E591 · ★★☆

#include <stdio.h>
#include "bst.h"

void faixa(const No *r, int min, int max, int *visitados) {
    if (r == NULL) {
        return;
    }
    (*visitados)++;
    if (r->chave > min) {
        faixa(r->esq, min, max, visitados); // pode ter resposta à esquerda
    }
    if (r->chave >= min && r->chave <= max) {
        printf(" %d", r->chave);
    }
    if (r->chave < max) {
        faixa(r->dir, min, max, visitados);
    }
}

int main(void) {
    int precos[] = {50, 30, 70, 20, 40, 60, 80, 10, 90};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = bst_insere(raiz, precos[i]);
    }

    int visitados = 0;
    printf("Entre 35 e 65:");
    faixa(raiz, 35, 65, &visitados);
    printf("\nNós visitados: %d de 9\n", visitados);

    raiz = bst_libera(raiz);
    return 0;
}
