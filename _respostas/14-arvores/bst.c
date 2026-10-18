// bst.c · implementação do TAD árvore binária de busca
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

static No *novo_no(int chave) {
    No *n = malloc(sizeof(No));
    if (n == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    n->chave = chave;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

No *bst_insere(No *r, int chave) {
    if (r == NULL) {
        return novo_no(chave); // achou o lugar vazio: vira folha
    }
    if (chave < r->chave) {
        r->esq = bst_insere(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = bst_insere(r->dir, chave);
    }
    return r; // igual: já existe, não insere de novo
}

No *bst_busca(No *r, int chave) {
    while (r != NULL && r->chave != chave) {
        r = chave < r->chave ? r->esq : r->dir;
    }
    return r;
}

No *bst_remove(No *r, int chave) {
    if (r == NULL) {
        return NULL; // não achou: nada a remover
    }
    if (chave < r->chave) {
        r->esq = bst_remove(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = bst_remove(r->dir, chave);
    } else if (r->esq == NULL || r->dir == NULL) {
        // folha ou um filho: o filho (ou NULL) sobe para o lugar do nó
        No *filho = r->esq != NULL ? r->esq : r->dir;
        free(r);
        return filho;
    } else {
        // dois filhos: copia o sucessor (o menor da direita) e remove ele lá
        No *suc = r->dir;
        while (suc->esq != NULL) {
            suc = suc->esq;
        }
        r->chave = suc->chave;
        r->dir = bst_remove(r->dir, suc->chave);
    }
    return r;
}

void bst_em_ordem(const No *r) {
    if (r == NULL) {
        return;
    }
    bst_em_ordem(r->esq);
    printf(" %d", r->chave);
    bst_em_ordem(r->dir);
}

int bst_altura(const No *r) {
    if (r == NULL) {
        return -1;
    }
    int he = bst_altura(r->esq);
    int hd = bst_altura(r->dir);
    return 1 + (he > hd ? he : hd);
}

No *bst_libera(No *r) {
    if (r != NULL) {
        bst_libera(r->esq);
        bst_libera(r->dir);
        free(r);
    }
    return NULL;
}
