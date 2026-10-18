// A202 · Mil pedidos: BST comum contra AVL

#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

// uma BST comum, sem balancear, só para comparar (nomes diferentes do TAD)
typedef struct Comum {
    int chave;
    struct Comum *esq, *dir;
} Comum;

Comum *comum_insere(Comum *r, int chave) {
    if (r == NULL) {
        Comum *n = malloc(sizeof(Comum));
        if (n == NULL) {
            exit(1);
        }
        n->chave = chave;
        n->esq = n->dir = NULL;
        return n;
    }
    if (chave < r->chave) {
        r->esq = comum_insere(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = comum_insere(r->dir, chave);
    }
    return r;
}

int comum_altura(const Comum *r) {
    if (r == NULL) {
        return -1;
    }
    int he = comum_altura(r->esq);
    int hd = comum_altura(r->dir);
    return 1 + (he > hd ? he : hd);
}

void comum_libera(Comum *r) {
    if (r != NULL) {
        comum_libera(r->esq);
        comum_libera(r->dir);
        free(r);
    }
}

int main(void) {
    Comum *bst = NULL;
    No *avl = NULL;
    for (int pedido = 1; pedido <= 1000; pedido++) { // em ordem crescente
        bst = comum_insere(bst, pedido);
        avl = avl_insere(avl, pedido);
    }

    printf("BST comum: altura %d\n", comum_altura(bst));
    printf("AVL:       altura %d, raiz %d, rotações %d\n",
           avl_altura(avl), avl->chave, avl_rotacoes());
    printf("Busca do pedido 1000: até %d comparações na BST, até %d na AVL\n",
           comum_altura(bst) + 1, avl_altura(avl) + 1);

    comum_libera(bst);
    avl = avl_libera(avl);
    return 0;
}
// Saída:
// BST comum: altura 999
// AVL:       altura 9, raiz 512, rotações 990
// Busca do pedido 1000: até 1000 comparações na BST, até 10 na AVL
