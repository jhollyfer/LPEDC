// A199 · Quando o sucessor também tem filho

#include <stdio.h>
#include "bst.h"

void pre(const No *r) {
    if (r == NULL) {
        return;
    }
    printf(" %d", r->chave);
    pre(r->esq);
    pre(r->dir);
}

void mostra(const char *rotulo, const No *r) {
    printf("%-14s pré:", rotulo);
    pre(r);
    printf(" (raiz %d)\n", r->chave);
}

int main(void) {
    // códigos dos produtos do estoque do mercadinho
    int codigos[] = {40, 20, 60, 50, 70, 55, 52};
    No *raiz = NULL;
    for (int i = 0; i < 7; i++) {
        raiz = bst_insere(raiz, codigos[i]);
    }
    mostra("Antes", raiz);

    // a raiz tem dois filhos; o sucessor (50) não é folha: tem o 55 à direita.
    // o 50 sobe para a raiz e o 55 (com o 52) sobe para o lugar dele
    raiz = bst_remove(raiz, 40);
    mostra("Remove 40", raiz);

    // o 20 era o único à esquerda: agora a raiz só tem filho direito
    raiz = bst_remove(raiz, 20);
    mostra("Remove 20", raiz);

    // raiz com UM filho: nada de sucessor, o filho direito vira a raiz
    raiz = bst_remove(raiz, 50);
    mostra("Remove 50", raiz);

    raiz = bst_libera(raiz);
    return 0;
}
// Saída:
// Antes          pré: 40 20 60 50 55 52 70 (raiz 40)
// Remove 40      pré: 50 20 60 55 52 70 (raiz 50)
// Remove 20      pré: 50 60 55 52 70 (raiz 50)
// Remove 50      pré: 60 55 52 70 (raiz 60)
