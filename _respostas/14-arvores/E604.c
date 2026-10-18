// 0101 · AVL: balanceamento e rotações
// Exercício E604 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void atualiza_altura(No *r) {
    int he = avl_altura(r->esq);
    int hd = avl_altura(r->dir);
    r->altura = 1 + (he > hd ? he : hd);
}

// cria um nó já com a altura certa (os filhos já existem)
No *no(int chave, No *esq, No *dir) {
    No *n = malloc(sizeof(No));
    if (n == NULL) {
        exit(1);
    }
    n->chave = chave;
    n->esq = esq;
    n->dir = dir;
    atualiza_altura(n);
    return n;
}

No *gira_direita(No *r) {
    No *e = r->esq;
    r->esq = e->dir;
    e->dir = r;
    atualiza_altura(r);
    atualiza_altura(e);
    return e;
}

No *gira_esquerda(No *r) {
    No *d = r->dir;
    r->dir = d->esq; // a subárvore do meio muda de pai
    d->esq = r;
    atualiza_altura(r); // r ficou embaixo: primeiro ele
    atualiza_altura(d);
    return d;
}

void mostra(const char *nome, const No *r) {
    printf("%s: pré", nome);
    avl_pre_ordem(r);
    printf(" | altura da raiz %d\n", avl_altura(r));
}

int main(void) {
    No *t1 = no(10, NULL, no(20, NULL, no(30, NULL, NULL)));
    No *t2 = no(40, no(20, NULL, NULL), no(60, no(50, NULL, NULL), no(70, NULL, NULL)));

    t1 = gira_esquerda(t1);
    t2 = gira_esquerda(t2);
    mostra("Teste 1", t1);
    mostra("Teste 2", t2);

    t1 = avl_libera(t1);
    t2 = avl_libera(t2);
    return 0;
}
