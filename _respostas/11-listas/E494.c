// 0083 · Lista ordenada
// Exercício E494 · ★☆☆
//
// Resposta (onde o laço para, e a lista depois):
//   25: ant NULL, p NULL (lista vazia)  -> 25
//   10: ant NULL, p no 25 (10 < 25)     -> 10 25
//   40: ant no 25, p NULL (fim)         -> 10 25 40
//   10: ant NULL, p no primeiro 10      -> 10 10 25 40
//       (10 < 10 é falso: o novo entra ANTES do 10 antigo)
//   30: ant no 25, p no 40              -> 10 10 25 30 40
//
// Com "<=", o segundo 10 passaria pelo primeiro (10 <= 10) e pararia com ant
// no 10 e p no 25: entraria DEPOIS dele. Com "<=" os iguais ficam na ordem
// de chegada; com "<", o mais novo fica na frente.

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

int main(void) {
    int valores[] = {25, 10, 40, 10, 30};
    No *l = NULL;
    for (int i = 0; i < 5; i++) {
        l = lista_insere_ordenado(l, valores[i]);
        printf("inseriu %d: ", valores[i]);
        lista_imprime(l);
    }
    lista_libera(l);
    return 0;
}
