// 0078 · Lista ordenada
// Exercício E468 · ★★★
//
// Custo: cada encaixe pode percorrer a lista ordenada inteira, então no pior
// caso são 0 + 1 + ... + (n-1) comparações: O(n²). Encaixar não desloca
// ninguém, ao contrário do insertion sort em vetor.

#include <stdio.h>

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

No *ordena(No *inicio) {
    No *ordenada = NULL;
    while (inicio != NULL) {
        No *no = inicio;        // desengata o primeiro
        inicio = inicio->prox;  // (o resto foi guardado antes)

        No *ant = NULL;
        No *p = ordenada;
        while (p != NULL && p->valor < no->valor) {
            ant = p;
            p = p->prox;
        }
        no->prox = p;
        if (ant == NULL) ordenada = no;
        else ant->prox = no;
    }
    return ordenada;
}

int main(void) {
    int pedidos[] = {4, 9, 1, 7, 3}; // inseridos no início: ficam ao contrário
    No *l = NULL;
    for (int i = 0; i < 5; i++) l = lista_insere_inicio(l, pedidos[i]);

    printf("antes:  ");
    lista_imprime(l);
    l = ordena(l);
    printf("depois: ");
    lista_imprime(l);

    lista_libera(l);
    return 0;
}
