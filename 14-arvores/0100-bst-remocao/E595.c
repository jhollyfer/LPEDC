// 0100 · BST: remoção
// Exercício E595 · ★☆☆
//
// O main monta a BST inserindo nesta ordem:
//
//   60 25 80 10 40 70 90 35 50
//
// e depois remove, um de cada vez, o 10, o 80 e o 25. Complete a função
// caso(r, chave), que acha o nó da chave e devolve qual dos três casos da
// remoção ele é: "folha", "um filho" ou "dois filhos" (ou "não existe"). O
// main chama caso ANTES de cada bst_remove e mostra a pré-ordem depois:
//
//   Saída esperada:
//   Antes:                  pré 60 25 10 40 35 50 80 70 90
//   Sem o 10 (folha):       pré 60 25 40 35 50 80 70 90
//   Sem o 80 (dois filhos): pré 60 25 40 35 50 90 70
//   Sem o 25 (um filho):    pré 60 40 35 50 90 70
//
// Dicas:
// 1. Ache o nó com bst_busca. Se vier NULL, devolva "não existe".
// 2. Conte quantos dos dois ponteiros (esq e dir) não são NULL: 0, 1 ou 2.
// 3. Resposta esperada: a saída acima. O 25 tinha dois filhos no começo, mas
//    depois que o 10 saiu ficou só com o 40.
//
// Escreva sua resposta abaixo (complete caso):

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

const char *caso(No *r, int chave) {
    (void)r; // apague estas duas linhas quando escrever a função
    (void)chave;
    return "?";
}

int main(void) {
    int chaves[] = {60, 25, 80, 10, 40, 70, 90, 35, 50};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = bst_insere(raiz, chaves[i]);
    }
    printf("%-24spré", "Antes:");
    pre(raiz);
    printf("\n");

    int sai[] = {10, 80, 25};
    char rotulo[32];
    for (int i = 0; i < 3; i++) {
        snprintf(rotulo, sizeof rotulo, "Sem o %d (%s):", sai[i], caso(raiz, sai[i]));
        raiz = bst_remove(raiz, sai[i]);
        printf("%-24spré", rotulo);
        pre(raiz);
        printf("\n");
    }
    raiz = bst_libera(raiz);
    return 0;
}
