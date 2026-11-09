// Lista · Módulo 14 · Árvores
// Exercício P1403 · ★☆☆ · Procurando o CEP na BST

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *esq, *dir;
} No;

No *insere(No *r, int chave) {
    if (r == NULL) {
        No *p = malloc(sizeof(No));
        if (p == NULL) {
            exit(1);
        }
        p->chave = chave;
        p->esq = p->dir = NULL;
        return p;
    }
    if (chave < r->chave) {
        r->esq = insere(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = insere(r->dir, chave);
    }
    return r;
}

// busca sem recursão, contando os nós visitados
const No *busca(const No *r, int chave, int *visitados) {
    *visitados = 0;
    while (r != NULL) {
        (*visitados)++;
        if (chave == r->chave) {
            return r;
        }
        r = (chave < r->chave) ? r->esq : r->dir;
    }
    return NULL;
}

int minimo(const No *r) {
    while (r->esq != NULL) {
        r = r->esq;
    }
    return r->chave;
}

int maximo(const No *r) {
    while (r->dir != NULL) {
        r = r->dir;
    }
    return r->chave;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    int ceps[] = {690, 420, 810, 150, 530, 770, 950, 480, 600};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = insere(raiz, ceps[i]);
    }

    int procurados[] = {600, 950, 690, 500};
    for (int k = 0; k < 4; k++) {
        int vis;
        const No *achou = busca(raiz, procurados[k], &vis);
        printf("%d: %s (visitados: %d)\n", procurados[k], achou ? "achou" : "não achou", vis);
    }
    printf("menor: %d, maior: %d\n", minimo(raiz), maximo(raiz));
    libera(raiz);
    return 0;
}
