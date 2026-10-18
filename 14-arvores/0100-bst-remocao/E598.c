// 0100 · BST: remoção
// Exercício E598 · ★★☆
//
// Ache o bug. Esta é uma cópia da remoção do TAD com UMA linha diferente.
// Ela deveria remover o 30 da árvore das matrículas, mas depois da remoção
// o 35 aparece duas vezes:
//
//   Saída esperada:
//   Em ordem: 20 35 40 45 50 60 70 80
//
//   Saída que aparece:
//   Em ordem: 20 35 35 40 45 50 60 70 80
//
// Ache a linha, conserte e explique o que a versão errada fazia. Por que o
// programa não deu erro de memória nem vazamento?
//
// Dicas:
// 1. O 35 foi copiado para o lugar do 30. E depois, qual chave a chamada
//    recursiva tenta remover da subárvore direita?
// 2. Existe algum 30 na subárvore direita do (antigo) 30?
// 3. Resposta esperada: a última linha do else (a dos dois filhos),
//    "r->dir = remove_errado(r->dir, chave);", deveria usar suc->chave.
//    Com chave (30), a recursão procura um 30 que não existe à direita e
//    não remove nada: o 35 fica duplicado. Não há
//    erro de memória porque nenhum nó foi liberado nem perdido; o bst_libera
//    do fim libera todos. Consertado: 20 35 40 45 50 60 70 80.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

No *remove_errado(No *r, int chave) {
    if (r == NULL) {
        return NULL;
    }
    if (chave < r->chave) {
        r->esq = remove_errado(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = remove_errado(r->dir, chave);
    } else if (r->esq == NULL || r->dir == NULL) {
        No *filho = r->esq != NULL ? r->esq : r->dir;
        free(r);
        return filho;
    } else {
        No *suc = r->dir;
        while (suc->esq != NULL) {
            suc = suc->esq;
        }
        r->chave = suc->chave;
        r->dir = remove_errado(r->dir, chave);
    }
    return r;
}

int main(void) {
    int matriculas[] = {50, 30, 70, 20, 40, 60, 80, 35, 45};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = bst_insere(raiz, matriculas[i]);
    }
    raiz = remove_errado(raiz, 30);
    printf("Em ordem:");
    bst_em_ordem(raiz);
    printf("\n");

    raiz = bst_libera(raiz);
    return 0;
}
