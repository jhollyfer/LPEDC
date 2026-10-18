// fila.c · fila circular sobre vetor (0090)
//
// Os itens ocupam n posições seguidas a partir de inicio, dando a volta no
// fim do vetor: inicio, inicio + 1, ..., sempre com % CAPACIDADE. A próxima
// vaga (o "fim") é (inicio + n) % CAPACIDADE.

#include <stdlib.h>
#include "fila.h"

#define CAPACIDADE 8

struct fila {
    int itens[CAPACIDADE];
    int inicio; // posição do primeiro da fila (o próximo a sair)
    int n;      // quantos estão na fila: separa "cheia" de "vazia"
};

Fila *fila_cria(void) {
    Fila *f = malloc(sizeof *f);
    if (f != NULL) {
        f->inicio = 0;
        f->n = 0;
    }
    return f;
}

void fila_libera(Fila *f) {
    free(f);
}

bool fila_vazia(const Fila *f) {
    return f->n == 0;
}

int fila_tamanho(const Fila *f) {
    return f->n;
}

bool fila_insere(Fila *f, int valor) {
    if (f->n == CAPACIDADE) {
        return false; // cheia
    }
    int fim = (f->inicio + f->n) % CAPACIDADE; // dá a volta no fim do vetor
    f->itens[fim] = valor;
    f->n++;
    return true;
}

bool fila_retira(Fila *f, int *valor) {
    if (f->n == 0) {
        return false; // vazia
    }
    *valor = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % CAPACIDADE;
    f->n--;
    return true;
}

bool fila_primeiro(const Fila *f, int *valor) {
    if (f->n == 0) {
        return false;
    }
    *valor = f->itens[f->inicio];
    return true;
}
