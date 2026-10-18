// A210 · Até a raiz vai embora

#include <stdio.h>
#include "bst.h"

int main(void) {
    int matriculas[] = {50, 30, 70, 20, 40, 60, 80};
    No *raiz = NULL;
    for (int i = 0; i < 7; i++) {
        raiz = bst_insere(raiz, matriculas[i]);
    }

    // remove sempre a raiz: o ponteiro raiz muda a cada passo
    while (raiz != NULL) {
        int sai = raiz->chave;
        raiz = bst_remove(raiz, sai);
        printf("Saiu %d, nova raiz: ", sai);
        if (raiz == NULL) {
            printf("NULL (árvore vazia)\n");
        } else {
            printf("%d, em ordem:", raiz->chave);
            bst_em_ordem(raiz);
            printf("\n");
        }
    }
    return 0; // nada a liberar: remove já deu free em cada nó
}
// Saída:
// Saiu 50, nova raiz: 60, em ordem: 20 30 40 60 70 80
// Saiu 60, nova raiz: 70, em ordem: 20 30 40 70 80
// Saiu 70, nova raiz: 80, em ordem: 20 30 40 80
// Saiu 80, nova raiz: 30, em ordem: 20 30 40
// Saiu 30, nova raiz: 40, em ordem: 20 40
// Saiu 40, nova raiz: 20, em ordem: 20
// Saiu 20, nova raiz: NULL (árvore vazia)
