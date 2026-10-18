// A208 · A ordem de chegada muda a árvore

#include <stdio.h>
#include "bst.h"

No *monta(const int v[], int n) {
    No *r = NULL;
    for (int i = 0; i < n; i++) {
        r = bst_insere(r, v[i]);
    }
    return r;
}

int main(void) {
    int embaralhada[] = {50, 30, 70, 20, 40, 60, 80};
    int crescente[] = {20, 30, 40, 50, 60, 70, 80};

    No *a = monta(embaralhada, 7);
    No *b = monta(crescente, 7);

    // as duas guardam as mesmas chaves: a em ordem é igual
    printf("A em ordem:");
    bst_em_ordem(a);
    printf("\nB em ordem:");
    bst_em_ordem(b);
    printf("\n");

    // mas a forma é outra: B virou uma lista, tudo pendurado à direita
    printf("Altura de A: %d\n", bst_altura(a));
    printf("Altura de B: %d\n", bst_altura(b));
    printf("Raiz de B: %d, filho esquerdo: %s\n", b->chave, b->esq == NULL ? "NULL" : "existe");

    a = bst_libera(a);
    b = bst_libera(b);
    return 0;
}
// Saída:
// A em ordem: 20 30 40 50 60 70 80
// B em ordem: 20 30 40 50 60 70 80
// Altura de A: 2
// Altura de B: 6
// Raiz de B: 20, filho esquerdo: NULL
