// 0105 · BST: remoção
// Exercício E625 · ★☆☆
//
// No papel, monte a BST inserindo nesta ordem:
//
//   60 25 80 10 40 70 90 35 50
//
// Depois remova, um de cada vez, o 10, o 80 e o 25. Para cada remoção diga
// qual dos três casos aconteceu (folha, um filho, dois filhos) e desenhe a
// árvore. O programa mostra a pré-ordem depois de cada passo: rode só para
// conferir.
//
// Dicas:
// 1. O 10 não tem filhos. O 80 tem 70 e 90.
// 2. Depois que o 10 sai, quantos filhos sobram para o 25?
// 3. Resposta esperada: 10 é folha; 80 tem dois filhos e o sucessor 90
//    assume; 25 ficou com um filho só (o 40), que sobe. No fim:
//    pré 60 40 35 50 90 70.
//
// Escreva sua resposta abaixo (como comentário):

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

int main(void) {
    int chaves[] = {60, 25, 80, 10, 40, 70, 90, 35, 50};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = bst_insere(raiz, chaves[i]);
    }
    int sai[] = {10, 80, 25};
    for (int i = 0; i < 3; i++) {
        raiz = bst_remove(raiz, sai[i]);
        printf("Sem o %d, pré:", sai[i]);
        pre(raiz);
        printf("\n");
    }
    raiz = bst_libera(raiz);
    return 0;
}
