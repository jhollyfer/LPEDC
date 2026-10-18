// lista.h · lista simplesmente encadeada: busca e remoção

#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef struct no {
    int valor;
    struct no *prox; // o próximo nó, ou NULL no último
} No;

// cria um nó com "valor" na frente e devolve o NOVO início
No *lista_insere_inicio(No *inicio, int valor);

// devolve o primeiro nó com "valor", ou NULL se não tiver
No *lista_busca(No *inicio, int valor);

// tira o primeiro nó com "valor". Recebe o ENDEREÇO do início, porque tirar
// o primeiro nó muda o início. Devolve false se o valor não estava na lista.
bool lista_remove(No **inicio, int valor);

// mostra a lista assim: 31 -> 17 -> NULL
void lista_imprime(const No *inicio);

// quantos nós a lista tem
int lista_tamanho(const No *inicio);

// devolve a memória de todos os nós
void lista_libera(No *inicio);

#endif
