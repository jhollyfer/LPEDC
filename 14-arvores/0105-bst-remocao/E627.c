// 0105 · BST: remoção
// Exercício E627 · ★★☆
//
// O bst_remove do TAD usa o sucessor. Escreva remove_antecessor(r, chave),
// a mesma remoção, mas que no caso de dois filhos usa o ANTECESSOR: a maior
// chave da subárvore esquerda. Teste na árvore das matrículas do texto,
// removendo o 30 e depois o 50:
//
//   Saída esperada:
//   Antes:     pré 50 30 20 40 35 45 70 60 80
//   Sem o 30:  pré 50 20 40 35 45 70 60 80
//   Sem o 50:  pré 45 20 40 35 70 60 80
//
// Dicas:
// 1. O antecessor: desça uma vez à esquerda e depois à direita até o fim.
//    Ele nunca tem filho direito.
// 2. Copie a chave dele para r e chame remove_antecessor(r->esq, ...) com a
//    chave do antecessor.
// 3. Resposta esperada: a saída acima. Sem o 30, o 20 assume (era folha).
//    Sem o 50, o 45 vira a raiz.
//
// Escreva sua resposta abaixo (complete remove_antecessor):

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
    (void)chave; // apague esta linha
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
