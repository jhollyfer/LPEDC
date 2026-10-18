// lista.h · lista circular simplesmente encadeada
//
// O último nó aponta de volta para o primeiro: nenhum prox é NULL. A lista é
// guardada pelo ponteiro para o ÚLTIMO nó, porque dele se chega às duas
// pontas: o primeiro é ultimo->prox. Lista vazia: No *ultimo = NULL;

#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef struct no {
    int valor;
    struct no *prox; // nunca NULL: o último aponta para o primeiro
} No;

// põe "valor" depois do último e devolve o NOVO último: O(1)
No *lista_insere_fim(No *ultimo, int valor);

// põe "valor" antes do primeiro e devolve o último (que só muda se a lista
// estava vazia): O(1)
No *lista_insere_inicio(No *ultimo, int valor);

// tira o primeiro nó com "valor"; false se não estava
bool lista_remove(No **ultimo, int valor);

// mostra uma volta, do primeiro ao último: 3 -> 7 -> (volta ao 3)
void lista_imprime(const No *ultimo);

// quantos nós a lista tem
int lista_tamanho(const No *ultimo);

// devolve a memória de todos os nós
void lista_libera(No *ultimo);

#endif
