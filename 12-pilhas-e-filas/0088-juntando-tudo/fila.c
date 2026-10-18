// fila.c · fila sobre lista encadeada (a mesma do 0086)
//
// Dois ponteiros: inicio (por onde sai) e fim (por onde entra). Sair é
// remover do começo da lista; entrar é pendurar um nó depois do último.
// Os dois custam O(1) porque o último está sempre à mão.

#include <stdlib.h>
#include "fila.h"

typedef struct no_fila {
    int valor;
    struct no_fila *prox; // quem está atrás na fila
} NoFila;

struct fila {
    NoFila *inicio; // o próximo a sair; NULL se vazia
    NoFila *fim;    // o último que entrou; NULL se vazia
    int n;
};

Fila *fila_cria(void) {
    Fila *f = malloc(sizeof *f);
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
        f->n = 0;
    }
    return f;
}

void fila_libera(Fila *f) {
    NoFila *atual = f->inicio;
    while (atual != NULL) {
        NoFila *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    free(f);
}

bool fila_vazia(const Fila *f) {
    return f->inicio == NULL;
}

int fila_tamanho(const Fila *f) {
    return f->n;
}

bool fila_insere(Fila *f, int valor) {
    NoFila *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return false;
    }
    novo->valor = valor;
    novo->prox = NULL; // vai ser o último
    if (f->fim == NULL) {
        f->inicio = novo; // fila vazia: o novo também é o primeiro
    } else {
        f->fim->prox = novo; // pendura atrás do último
    }
    f->fim = novo;
    f->n++;
    return true;
}

bool fila_retira(Fila *f, int *valor) {
    if (f->inicio == NULL) {
        return false;
    }
    NoFila *velho = f->inicio;
    *valor = velho->valor;
    f->inicio = velho->prox;
    if (f->inicio == NULL) {
        f->fim = NULL; // saiu o último: o fim não pode apontar para o nó liberado
    }
    free(velho);
    f->n--;
    return true;
}

bool fila_primeiro(const Fila *f, int *valor) {
    if (f->inicio == NULL) {
        return false;
    }
    *valor = f->inicio->valor;
    return true;
}
