// 0076 · Lista encadeada
// Exercício E452 · ★☆☆

#include <stdio.h>
// ---- lista.h e lista.c colados aqui, para esta resolução rodar sozinha ----
// lista.h · lista simplesmente encadeada de inteiros
//
// Aqui a struct do nó fica no .h DE PROPÓSITO: o assunto é justamente mexer
// nos nós (p->valor, p->prox). A lista é um ponteiro para o primeiro nó, e a
// lista vazia é NULL:  No *inicio = NULL;

#ifndef LISTA_H
#define LISTA_H

typedef struct no {
    int valor;
    struct no *prox; // o próximo nó, ou NULL no último
} No;

// cria um nó com "valor" na frente da lista e devolve o NOVO início:
//   inicio = lista_insere_inicio(inicio, 20);
No *lista_insere_inicio(No *inicio, int valor);

// mostra a lista assim: 80 -> 10 -> 45 -> NULL
void lista_imprime(const No *inicio);

// quantos nós a lista tem
int lista_tamanho(const No *inicio);

// devolve a memória de todos os nós
void lista_libera(No *inicio);

#endif

// lista.c · implementação da lista simplesmente encadeada

#include <stdio.h>
#include <stdlib.h>

No *lista_insere_inicio(No *inicio, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) { // num programa pequeno, desistir é o mais honesto
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = inicio; // o antigo primeiro vira o segundo
    return novo;         // o novo nó é o novo início
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
        No *seguinte = p->prox; // guarda ANTES do free
        free(p);
        p = seguinte;
    }
}
// ---- fim de lista.h e lista.c ----

int main(void) {
    No *l = NULL;
    for (int i = 1; i <= 4; i++) {
        l = lista_insere_inicio(l, i * 3);
    }
    lista_imprime(l);
    printf("primeiro: %d\n", l->valor);
    printf("terceiro: %d\n", l->prox->prox->valor);

    No *p = l;
    while (p->prox != NULL) {
        p = p->prox;
    }
    printf("último: %d\n", p->valor);

    lista_libera(l);
    return 0;
}
