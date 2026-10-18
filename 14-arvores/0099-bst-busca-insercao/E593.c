// 0099 · BST: busca e inserção
// Exercício E593 · ★★★
//
// Ache o bug. A função eh_bst deveria dizer se uma árvore respeita a regra da
// BST. As duas árvores abaixo foram montadas à mão (sem bst_insere):
//
//   árvore 1          árvore 2
//   50                50
//   ├── esq: 30       ├── esq: 30
//   │   ├── esq: 20   │   ├── esq: 20
//   │   └── dir: 60   │   └── dir: 40
//   └── dir: 80       └── dir: 80
//       ├── esq: 70       ├── esq: 70
//       └── dir: 90       └── dir: 90
//
//   Saída que aparece:
//   Árvore 1: é BST
//   Árvore 2: é BST
//   Busca 60 na árvore 1: não achou
//
// A árvore 1 NÃO é BST, e a prova é a terceira linha: o 60 está lá, mas a
// busca não acha. Explique por que eh_bst erra e reescreva a função para dar
// "não é BST" na árvore 1 e "é BST" na árvore 2.
//
// Dicas:
// 1. A função só compara cada nó com os FILHOS. Olhe o 60 em relação ao 50.
// 2. A regra vale para a subárvore inteira: cada nó tem uma faixa permitida.
//    Escreva entre(r, min, max): a raiz começa com (INT_MIN, INT_MAX); ao
//    descer para a esquerda, o máximo vira r->chave; para a direita, o
//    mínimo vira r->chave.
// 3. Resposta esperada: o 60 é maior que o pai (30), mas está à esquerda do
//    50, então devia ser menor que 50. Corrigido: "Árvore 1: não é BST" e
//    "Árvore 2: é BST". (A busca continua não achando o 60 na árvore 1:
//    a culpa é da árvore, não da busca.)
//
// Escreva sua resposta abaixo (conserte eh_bst):

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

bool eh_bst(const No *r) {
    if (r == NULL) {
        return true;
    }
    if (r->esq != NULL && r->esq->chave >= r->chave) {
        return false;
    }
    if (r->dir != NULL && r->dir->chave <= r->chave) {
        return false;
    }
    return eh_bst(r->esq) && eh_bst(r->dir);
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
