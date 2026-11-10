// 0100 · BST: remoção
// Exercício E599 · ★★★
//
// A academia vai encerrar a turma das matrículas de 35 a 65. Escreva
// remove_faixa(r, a, b), que remove da BST todas as chaves no intervalo
// [a, b] e devolve a nova raiz. Teste na árvore das matrículas do texto:
//
//   Saída esperada:
//   Antes:  20 30 35 40 45 50 60 70 80
//   Depois: 20 30 70 80
//   Raiz: 70, altura: 2
//
// Escreva sua resposta abaixo (complete remove_faixa):

#include <stdio.h>
#include "bst.h"

No *remove_faixa(No *r, int a, int b) {
    (void)a; // apague estas duas linhas
    (void)b;
    return r;
}

int main(void) {
    int matriculas[] = {50, 30, 70, 20, 40, 60, 80, 35, 45};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = bst_insere(raiz, matriculas[i]);
    }
    printf("Antes: ");
    bst_em_ordem(raiz);
    raiz = remove_faixa(raiz, 35, 65);
    printf("\nDepois:");
    bst_em_ordem(raiz);
    printf("\nRaiz: %d, altura: %d\n", raiz->chave, bst_altura(raiz));

    raiz = bst_libera(raiz);
    return 0;
}
