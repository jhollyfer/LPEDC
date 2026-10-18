// 0105 · BST: remoção
// Exercício E626 · ★☆☆

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

No *remove_menor(No *r, int *senha) {
    if (r->esq == NULL) {
        *senha = r->chave;  // r é o menor
        No *direita = r->dir; // guarda antes do free
        free(r);
        return direita;
    }
    r->esq = remove_menor(r->esq, senha);
    return r;
}

int main(void) {
    int senhas[] = {30, 20, 50, 40, 70};
    No *raiz = NULL;
    for (int i = 0; i < 5; i++) {
        raiz = bst_insere(raiz, senhas[i]);
    }
    for (int i = 0; i < 3; i++) {
        int senha = 0;
        raiz = remove_menor(raiz, &senha);
        printf("Chamando %d, restam:", senha);
        bst_em_ordem(raiz);
        printf("\n");
    }
    raiz = bst_libera(raiz);
    return 0;
}
