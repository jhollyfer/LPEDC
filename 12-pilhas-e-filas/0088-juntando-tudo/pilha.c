// pilha.c · pilha sobre lista encadeada (a mesma do 0083)
//
// O topo é o PRIMEIRO nó da lista: empilhar é inserir no início e
// desempilhar é remover do início. Os dois custam O(1).

#include <stdlib.h>
#include "pilha.h"

typedef struct no {
    int valor;
    struct no *prox; // o nó de baixo
} No;

struct pilha {
    No *topo; // NULL quando a pilha está vazia
    int n;    // quantos itens (para pilha_tamanho não percorrer a lista)
};

Pilha *pilha_cria(void) {
    Pilha *p = malloc(sizeof *p);
    if (p != NULL) {
        p->topo = NULL;
        p->n = 0;
    }
    return p;
}

void pilha_libera(Pilha *p) {
    No *atual = p->topo;
    while (atual != NULL) {
        No *prox = atual->prox; // guarda antes de liberar
        free(atual);
        atual = prox;
    }
    free(p);
}

bool pilha_vazia(const Pilha *p) {
    return p->topo == NULL;
}

int pilha_tamanho(const Pilha *p) {
    return p->n;
}

bool pilha_empilha(Pilha *p, int valor) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return false; // só "enche" quando acaba a memória
    }
    novo->valor = valor;
    novo->prox = p->topo; // o novo aponta para o antigo topo
    p->topo = novo;       // e passa a ser o topo
    p->n++;
    return true;
}

bool pilha_desempilha(Pilha *p, int *valor) {
    if (p->topo == NULL) {
        return false;
    }
    No *velho = p->topo;
    *valor = velho->valor; // lê ANTES de liberar
    p->topo = velho->prox;
    free(velho);
    p->n--;
    return true;
}

bool pilha_topo(const Pilha *p, int *valor) {
    if (p->topo == NULL) {
        return false;
    }
    *valor = p->topo->valor;
    return true;
}
