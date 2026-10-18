// pilha.c · pilha sobre vetor (0082)
//
// Os itens ficam em itens[0..n-1]. O fundo é itens[0] e o topo é itens[n-1];
// n também é a primeira posição livre, onde entra o próximo.

#include <stdlib.h>
#include "pilha.h"

#define CAPACIDADE 100

struct pilha {
    int itens[CAPACIDADE];
    int n; // quantos itens estão na pilha
};

Pilha *pilha_cria(void) {
    Pilha *p = malloc(sizeof *p);
    if (p != NULL) {
        p->n = 0;
    }
    return p;
}

void pilha_libera(Pilha *p) {
    free(p);
}

bool pilha_vazia(const Pilha *p) {
    return p->n == 0;
}

int pilha_tamanho(const Pilha *p) {
    return p->n;
}

bool pilha_empilha(Pilha *p, int valor) {
    if (p->n == CAPACIDADE) {
        return false; // cheia: estouro (overflow)
    }
    p->itens[p->n] = valor;
    p->n++;
    return true;
}

bool pilha_desempilha(Pilha *p, int *valor) {
    if (p->n == 0) {
        return false; // vazia: nada para tirar (underflow)
    }
    p->n--;
    *valor = p->itens[p->n]; // o valor continua no vetor, mas saiu da pilha
    return true;
}

bool pilha_topo(const Pilha *p, int *valor) {
    if (p->n == 0) {
        return false;
    }
    *valor = p->itens[p->n - 1];
    return true;
}
