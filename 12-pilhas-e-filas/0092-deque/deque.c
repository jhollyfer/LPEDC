// deque.c · deque sobre vetor circular (0092)
//
// Como na fila do 0090: n itens seguidos a partir de inicio, dando a volta
// com % CAPACIDADE. A novidade é andar para TRÁS: inserir no início faz o
// inicio recuar uma gaveta, e da gaveta 0 ele volta para a última.

#include <stdlib.h>
#include "deque.h"

#define CAPACIDADE 8

struct deque {
    int itens[CAPACIDADE];
    int inicio; // posição do primeiro
    int n;      // quantos itens
};

// gaveta anterior a i, dando a volta: anterior(0) = CAPACIDADE - 1
static int anterior(int i) {
    return (i - 1 + CAPACIDADE) % CAPACIDADE; // (i - 1) % CAPACIDADE daria -1 com i = 0
}

Deque *deque_cria(void) {
    Deque *d = malloc(sizeof *d);
    if (d != NULL) {
        d->inicio = 0;
        d->n = 0;
    }
    return d;
}

void deque_libera(Deque *d) {
    free(d);
}

bool deque_vazio(const Deque *d) {
    return d->n == 0;
}

int deque_tamanho(const Deque *d) {
    return d->n;
}

bool deque_insere_inicio(Deque *d, int valor) {
    if (d->n == CAPACIDADE) {
        return false;
    }
    d->inicio = anterior(d->inicio); // o início recua uma gaveta
    d->itens[d->inicio] = valor;
    d->n++;
    return true;
}

bool deque_insere_fim(Deque *d, int valor) {
    if (d->n == CAPACIDADE) {
        return false;
    }
    d->itens[(d->inicio + d->n) % CAPACIDADE] = valor;
    d->n++;
    return true;
}

bool deque_retira_inicio(Deque *d, int *valor) {
    if (d->n == 0) {
        return false;
    }
    *valor = d->itens[d->inicio];
    d->inicio = (d->inicio + 1) % CAPACIDADE;
    d->n--;
    return true;
}

bool deque_retira_fim(Deque *d, int *valor) {
    if (d->n == 0) {
        return false;
    }
    *valor = d->itens[(d->inicio + d->n - 1) % CAPACIDADE]; // o último ocupado
    d->n--;
    return true;
}

bool deque_primeiro(const Deque *d, int *valor) {
    if (d->n == 0) {
        return false;
    }
    *valor = d->itens[d->inicio];
    return true;
}

bool deque_ultimo(const Deque *d, int *valor) {
    if (d->n == 0) {
        return false;
    }
    *valor = d->itens[(d->inicio + d->n - 1) % CAPACIDADE];
    return true;
}
