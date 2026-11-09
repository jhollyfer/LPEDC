// sentinela.c · implementação do TAD lista dupla circular com sentinela
#include <stdio.h>
#include <stdlib.h>
#include "sentinela.h"

ListaS *sent_cria(void) {
    ListaS *L = malloc(sizeof(ListaS));
    if (L == NULL) {
        return NULL;
    }
    L->nil.chave = 0;
    L->nil.prox = &L->nil; // vazia: a sentinela aponta para ela mesma
    L->nil.ant = &L->nil;
    L->n = 0;
    return L;
}

NoS *sent_insere_apos(ListaS *L, NoS *y, int chave) {
    NoS *x = malloc(sizeof(NoS));
    if (x == NULL) {
        return NULL;
    }
    x->chave = chave;
    x->prox = y->prox; // y sempre tem vizinho: no mínimo, a sentinela
    x->ant = y;
    y->prox->ant = x;
    y->prox = x;
    L->n++;
    return x;
}

NoS *sent_insere_inicio(ListaS *L, int chave) {
    return sent_insere_apos(L, &L->nil, chave);
}

NoS *sent_insere_fim(ListaS *L, int chave) {
    return sent_insere_apos(L, L->nil.ant, chave);
}

NoS *sent_busca(ListaS *L, int chave) {
    L->nil.chave = chave; // a sentinela guarda a chave: o laço sempre para
    NoS *x = L->nil.prox;
    while (x->chave != chave) {
        x = x->prox;
    }
    return x; // se for &L->nil, a chave não estava na lista
}

void sent_remove(ListaS *L, NoS *x) {
    x->ant->prox = x->prox;
    x->prox->ant = x->ant;
    free(x);
    L->n--;
}

void sent_mostra(const ListaS *L) {
    printf("[");
    for (const NoS *x = L->nil.prox; x != &L->nil; x = x->prox) {
        printf(" %d", x->chave);
    }
    printf(" ]\n");
}

void sent_mostra_inverso(const ListaS *L) {
    printf("[");
    for (const NoS *x = L->nil.ant; x != &L->nil; x = x->ant) {
        printf(" %d", x->chave);
    }
    printf(" ]\n");
}

void sent_libera(ListaS *L) {
    NoS *x = L->nil.prox;
    while (x != &L->nil) {
        NoS *seguinte = x->prox;
        free(x);
        x = seguinte;
    }
    free(L);
}
