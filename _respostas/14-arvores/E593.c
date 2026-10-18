// 0099 · BST: busca e inserção
// Exercício E593 · ★★★
//
// Resposta: a versão original só compara cada nó com os filhos diretos. O 60
// é maior que o pai (30), mas está na subárvore esquerda do 50 e deveria ser
// menor que 50. A regra vale para a subárvore inteira: cada nó herda uma
// faixa (min, max) dos ancestrais.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "bst.h"

No *no(int chave, No *esq, No *dir) {
    No *n = malloc(sizeof(No));
    if (n == NULL) {
        exit(1);
    }
    n->chave = chave;
    n->esq = esq;
    n->dir = dir;
    return n;
}

// toda chave da subárvore r precisa estar entre min e max
bool entre(const No *r, int min, int max) {
    if (r == NULL) {
        return true;
    }
    if (r->chave <= min || r->chave >= max) {
        return false;
    }
    return entre(r->esq, min, r->chave) && entre(r->dir, r->chave, max);
}

bool eh_bst(const No *r) {
    return entre(r, INT_MIN, INT_MAX);
}

int main(void) {
    No *a1 = no(50, no(30, no(20, NULL, NULL), no(60, NULL, NULL)),
                no(80, no(70, NULL, NULL), no(90, NULL, NULL)));
    No *a2 = no(50, no(30, no(20, NULL, NULL), no(40, NULL, NULL)),
                no(80, no(70, NULL, NULL), no(90, NULL, NULL)));

    printf("Árvore 1: %s\n", eh_bst(a1) ? "é BST" : "não é BST");
    printf("Árvore 2: %s\n", eh_bst(a2) ? "é BST" : "não é BST");
    printf("Busca 60 na árvore 1: %s\n", bst_busca(a1, 60) ? "achou" : "não achou");

    a1 = bst_libera(a1);
    a2 = bst_libera(a2);
    return 0;
}
