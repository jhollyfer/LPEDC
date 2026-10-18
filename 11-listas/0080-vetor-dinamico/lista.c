// lista.c · implementação da lista sequencial (vetor que cresce)

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista {
    int *itens; // vetor no heap
    int tam;    // quantos itens estão em uso
    int cap;    // quantos itens cabem no vetor
};

Lista *lista_cria(int capacidade) {
    if (capacidade < 1) capacidade = 1;
    Lista *l = malloc(sizeof(Lista));
    if (l == NULL) return NULL;
    l->itens = malloc(capacidade * sizeof(int));
    if (l->itens == NULL) {
        free(l);
        return NULL;
    }
    l->tam = 0;
    l->cap = capacidade;
    return l;
}

void lista_libera(Lista *l) {
    if (l == NULL) return;
    free(l->itens); // primeiro o vetor...
    free(l);        // ...depois a struct que apontava para ele
}

// garante espaço para mais um item: se encheu, dobra
static bool garante_espaco(Lista *l) {
    if (l->tam < l->cap) return true;
    int nova_cap = l->cap * 2;
    int *novo = realloc(l->itens, nova_cap * sizeof(int));
    if (novo == NULL) return false; // l->itens continua valendo
    l->itens = novo;
    l->cap = nova_cap;
    return true;
}

bool lista_insere_fim(Lista *l, int valor) {
    if (!garante_espaco(l)) return false;
    l->itens[l->tam] = valor;
    l->tam++;
    return true;
}

bool lista_insere_em(Lista *l, int pos, int valor) {
    if (pos < 0 || pos > l->tam) return false;
    if (!garante_espaco(l)) return false;
    for (int i = l->tam; i > pos; i--) { // abre o buraco, de trás para frente
        l->itens[i] = l->itens[i - 1];
    }
    l->itens[pos] = valor;
    l->tam++;
    return true;
}

bool lista_remove_em(Lista *l, int pos, int *removido) {
    if (pos < 0 || pos >= l->tam) return false;
    if (removido != NULL) *removido = l->itens[pos];
    for (int i = pos; i < l->tam - 1; i++) { // fecha o buraco
        l->itens[i] = l->itens[i + 1];
    }
    l->tam--;
    return true;
}

bool lista_pega(const Lista *l, int pos, int *valor) {
    if (pos < 0 || pos >= l->tam) return false;
    *valor = l->itens[pos];
    return true;
}

int lista_tamanho(const Lista *l) {
    return l->tam;
}

int lista_capacidade(const Lista *l) {
    return l->cap;
}

void lista_imprime(const Lista *l) {
    printf("[");
    for (int i = 0; i < l->tam; i++) {
        if (i > 0) printf(", ");
        printf("%d", l->itens[i]);
    }
    printf("]\n");
}
