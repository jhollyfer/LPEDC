// A197 · Onde cada pedido vai morar

#include <stdio.h>
#include "bst.h"

// antes de inserir, refaz a descida que o insere vai fazer e conta onde a
// chave vai virar folha (ou se já existe)
void anuncia(const No *r, int chave) {
    printf("%2d:", chave);
    if (r == NULL) {
        printf(" árvore vazia, vira a raiz\n");
        return;
    }
    while (1) {
        printf(" %d", r->chave);
        if (chave == r->chave) {
            printf(" -> já existe, ignorado\n");
            return;
        }
        const No *prox = chave < r->chave ? r->esq : r->dir;
        if (prox == NULL) {
            printf(" -> filho %s do %d\n", chave < r->chave ? "esquerdo" : "direito", r->chave);
            return;
        }
        r = prox;
    }
}

int main(void) {
    // números dos pedidos da lanchonete, na ordem em que chegaram
    int pedidos[] = {42, 17, 63, 8, 25, 50, 25, 30};
    No *raiz = NULL;
    for (int i = 0; i < 8; i++) {
        anuncia(raiz, pedidos[i]);
        raiz = bst_insere(raiz, pedidos[i]);
    }

    // o primeiro que chegou continua na raiz: inserir nunca mexe no que já está
    printf("Raiz: %d\n", raiz->chave);
    printf("Altura: %d\n", bst_altura(raiz));

    raiz = bst_libera(raiz);
    return 0;
}
// Saída:
// 42: árvore vazia, vira a raiz
// 17: 42 -> filho esquerdo do 42
// 63: 42 -> filho direito do 42
//  8: 42 17 -> filho esquerdo do 17
// 25: 42 17 -> filho direito do 17
// 50: 42 63 -> filho esquerdo do 63
// 25: 42 17 25 -> já existe, ignorado
// 30: 42 17 25 -> filho direito do 25
// Raiz: 42
// Altura: 3
