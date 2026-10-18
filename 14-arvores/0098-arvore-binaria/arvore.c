// arvore.c · implementação do TAD árvore binária
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

No *arv_cria(char info, No *esq, No *dir) {
    No *n = malloc(sizeof(No));
    if (n == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    n->info = info;
    n->esq = esq;
    n->dir = dir;
    return n;
}

void arv_pre_ordem(const No *r) {
    if (r == NULL) {
        return;
    }
    printf(" %c", r->info);
    arv_pre_ordem(r->esq);
    arv_pre_ordem(r->dir);
}

void arv_em_ordem(const No *r) {
    if (r == NULL) {
        return;
    }
    arv_em_ordem(r->esq);
    printf(" %c", r->info);
    arv_em_ordem(r->dir);
}

void arv_pos_ordem(const No *r) {
    if (r == NULL) {
        return;
    }
    arv_pos_ordem(r->esq);
    arv_pos_ordem(r->dir);
    printf(" %c", r->info);
}

// por nível usa uma fila: sai um nó, entram os filhos dele
void arv_por_nivel(const No *r) {
    int n = arv_conta(r);
    if (n == 0) {
        return;
    }
    const No **fila = malloc(n * sizeof(No *));
    if (fila == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    int ini = 0, fim = 0;
    fila[fim++] = r;
    while (ini < fim) {
        const No *atual = fila[ini++];
        printf(" %c", atual->info);
        if (atual->esq != NULL) {
            fila[fim++] = atual->esq;
        }
        if (atual->dir != NULL) {
            fila[fim++] = atual->dir;
        }
    }
    free(fila);
}

int arv_conta(const No *r) {
    if (r == NULL) {
        return 0;
    }
    return 1 + arv_conta(r->esq) + arv_conta(r->dir);
}

int arv_altura(const No *r) {
    if (r == NULL) {
        return -1;
    }
    int he = arv_altura(r->esq);
    int hd = arv_altura(r->dir);
    return 1 + (he > hd ? he : hd);
}

// pós-ordem: as subárvores antes do nó
No *arv_libera(No *r) {
    if (r != NULL) {
        arv_libera(r->esq);
        arv_libera(r->dir);
        free(r);
    }
    return NULL;
}
