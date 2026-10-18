// 0078 · Lista ordenada
// Exercício E467 · ★★★
//
// Os três erros: (1) o while testava p->valor antes de p != NULL; (2) sem o
// caso "ant == NULL", inserir na frente fazia ant->prox com ant NULL; (3) o
// main jogava fora o início devolvido por insere_ordem.

#include <stdio.h>
#include <stdlib.h>

// ---- lista.h e lista.c colados aqui, para esta resolução rodar sozinha ----
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

// lista.c · lista simplesmente encadeada em ordem crescente

#include <stdio.h>
#include <stdlib.h>

static No *cria_no(int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

No *lista_insere_ordenado(No *inicio, int valor) {
    No *novo = cria_no(valor);
    No *ant = NULL;
    No *p = inicio;
    while (p != NULL && p->valor < valor) { // anda enquanto os de lá são menores
        ant = p;
        p = p->prox;
    }
    novo->prox = p;         // o novo aponta para o primeiro maior (ou NULL)
    if (ant == NULL) {
        return novo;        // é o menor de todos: vira o início
    }
    ant->prox = novo;       // o anterior passa a apontar para o novo
    return inicio;
}

No *lista_insere_inicio(No *inicio, int valor) {
    No *novo = cria_no(valor);
    novo->prox = inicio;
    return novo;
}

No *lista_busca_ordenada(No *inicio, int valor) {
    No *p = inicio;
    while (p != NULL && p->valor < valor) {
        p = p->prox;
    }
    if (p != NULL && p->valor == valor) return p;
    return NULL; // a lista acabou ou já passou do valor
}

bool lista_remove(No **inicio, int valor) {
    No *ant = NULL;
    No *p = *inicio;
    while (p != NULL && p->valor != valor) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) return false;
    if (ant == NULL) *inicio = p->prox;
    else ant->prox = p->prox;
    free(p);
    return true;
}

void lista_imprime(const No *inicio) {
    for (const No *p = inicio; p != NULL; p = p->prox) {
        printf("%d -> ", p->valor);
    }
    printf("NULL\n");
}

int lista_tamanho(const No *inicio) {
    int n = 0;
    for (const No *p = inicio; p != NULL; p = p->prox) n++;
    return n;
}

void lista_libera(No *inicio) {
    No *p = inicio;
    while (p != NULL) {
        No *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
}
// ---- fim de lista.h e lista.c ----

static No *insere_ordem(No *inicio, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) exit(1);
    novo->valor = valor;

    No *ant = NULL;
    No *p = inicio;
    while (p != NULL && p->valor < valor) {
        ant = p;
        p = p->prox;
    }
    novo->prox = p;
    if (ant == NULL) return novo;
    ant->prox = novo;
    return inicio;
}

int main(void) {
    int tempos[] = {1520, 1385, 1610, 1290};
    No *ranking = NULL;
    for (int i = 0; i < 4; i++) {
        ranking = insere_ordem(ranking, tempos[i]);
    }
    lista_imprime(ranking);
    lista_libera(ranking);
    return 0;
}
