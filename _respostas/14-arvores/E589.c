// 0099 · BST: busca e inserção
// Exercício E589 · ★☆☆

#include <stdio.h>
#include "bst.h"

// desce como a busca, contando os níveis
int nivel_de(const No *r, int chave) {
    int nivel = 0;
    while (r != NULL) {
        if (chave == r->chave) {
            return nivel;
        }
        r = chave < r->chave ? r->esq : r->dir;
        nivel++;
    }
    return -1; // caiu num NULL: não existe
}

int main(void) {
    int senhas[] = {45, 20, 70, 10, 30, 60, 90, 25};
    No *raiz = NULL;
    for (int i = 0; i < 8; i++) {
        raiz = bst_insere(raiz, senhas[i]);
    }

    printf("Em ordem:");
    bst_em_ordem(raiz);
    printf("\nAltura: %d\n", bst_altura(raiz));

    int testes[] = {45, 70, 30, 25, 65};
    for (int i = 0; i < 5; i++) {
        printf("Senha %d: nível %d\n", testes[i], nivel_de(raiz, testes[i]));
    }

    raiz = bst_libera(raiz);
    return 0;
}
