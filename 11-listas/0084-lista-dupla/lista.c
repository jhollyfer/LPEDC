// lista.c · lista duplamente encadeada de inteiros

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void lista_inicia(Lista *l) {
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;
}

static No *cria_no(int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) return NULL;
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

bool lista_insere_inicio(Lista *l, int valor) {
    No *novo = cria_no(valor);
    if (novo == NULL) return false;
    novo->prox = l->inicio;
    if (l->inicio != NULL) {
        l->inicio->ant = novo; // o antigo primeiro ganha um anterior
    } else {
        l->fim = novo;         // lista vazia: o novo também é o último
    }
    l->inicio = novo;
    l->tamanho++;
    return true;
}

bool lista_insere_fim(Lista *l, int valor) {
    No *novo = cria_no(valor);
    if (novo == NULL) return false;
    novo->ant = l->fim;
    if (l->fim != NULL) {
        l->fim->prox = novo;   // o antigo último ganha um próximo
    } else {
        l->inicio = novo;      // lista vazia: o novo também é o primeiro
    }
    l->fim = novo;
    l->tamanho++;
    return true;
}

No *lista_busca(const Lista *l, int valor) {
    No *p = l->inicio;
    while (p != NULL && p->valor != valor) p = p->prox;
    return p;
}

void lista_remove_no(Lista *l, No *p) {
    if (p->ant == NULL) l->inicio = p->prox;  // era o primeiro
    else p->ant->prox = p->prox;              // o anterior pula o p
    if (p->prox == NULL) l->fim = p->ant;     // era o último
    else p->prox->ant = p->ant;               // o seguinte pula o p para trás
    free(p);
    l->tamanho--;
}

void lista_imprime(const Lista *l) {
    if (l->inicio == NULL) {
        printf("(vazia)\n");
        return;
    }
    for (const No *p = l->inicio; p != NULL; p = p->prox) {
        printf(p->prox != NULL ? "%d <-> " : "%d\n", p->valor);
    }
}

void lista_imprime_reverso(const Lista *l) {
    if (l->fim == NULL) {
        printf("(vazia)\n");
        return;
    }
    for (const No *p = l->fim; p != NULL; p = p->ant) {
        printf(p->ant != NULL ? "%d <-> " : "%d\n", p->valor);
    }
}

void lista_libera(Lista *l) {
    No *p = l->inicio;
    while (p != NULL) {
        No *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
    lista_inicia(l);
}
