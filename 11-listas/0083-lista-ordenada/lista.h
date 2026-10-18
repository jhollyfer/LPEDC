// lista.h · lista simplesmente encadeada em ordem crescente

#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef struct no {
    int valor;
    struct no *prox; // o próximo nó, ou NULL no último
} No;

// põe "valor" no lugar certo (ordem crescente) e devolve o NOVO início:
//   inicio = lista_insere_ordenado(inicio, 1015);
No *lista_insere_ordenado(No *inicio, int valor);

// põe "valor" na frente, sem olhar a ordem (útil para montar listas
// desordenadas nos exercícios) e devolve o NOVO início
No *lista_insere_inicio(No *inicio, int valor);

// busca numa lista crescente: desiste assim que passa do valor
No *lista_busca_ordenada(No *inicio, int valor);

// tira o primeiro nó com "valor"; false se não estava
bool lista_remove(No **inicio, int valor);

// mostra a lista assim: 3 -> 7 -> NULL
void lista_imprime(const No *inicio);

// quantos nós a lista tem
int lista_tamanho(const No *inicio);

// devolve a memória de todos os nós
void lista_libera(No *inicio);

#endif
