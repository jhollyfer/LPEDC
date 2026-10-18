// 0077 · Busca e remoção
// Exercício E459 · ★★☆

#include <stdio.h>
#include <stdlib.h>

// ---- lista.h e lista.c colados aqui, para esta resolução rodar sozinha ----
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

// lista.c · lista simplesmente encadeada: busca e remoção

#include <stdio.h>
#include <stdlib.h>

No *lista_insere_inicio(No *inicio, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = inicio;
    return novo;
}

No *lista_busca(No *inicio, int valor) {
    No *p = inicio;
    while (p != NULL && p->valor != valor) { // o teste do NULL vem primeiro
        p = p->prox;
    }
    return p; // o nó, ou NULL se a lista acabou
}

bool lista_remove(No **inicio, int valor) {
    No *ant = NULL;    // sempre um passo atrás de p
    No *p = *inicio;
    while (p != NULL && p->valor != valor) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) return false; // não achou
    if (ant == NULL) {
        *inicio = p->prox;       // era o primeiro: o início anda
    } else {
        ant->prox = p->prox;     // o anterior pula o p
    }
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

int remove_todos(No **inicio, int valor) {
    int tirou = 0;
    No *ant = NULL;
    No *p = *inicio;
    while (p != NULL) {
        if (p->valor == valor) {
            No *seguinte = p->prox;
            if (ant == NULL) *inicio = seguinte;
            else ant->prox = seguinte;
            free(p);
            p = seguinte; // o ant fica onde está
            tirou++;
        } else {
            ant = p;
            p = p->prox;
        }
    }
    return tirou;
}

int main(void) {
    int leituras[] = {0, 19, 0, 21, 0, 0}; // inseridas no início: ficam ao contrário
    No *l = NULL;
    for (int i = 0; i < 6; i++) l = lista_insere_inicio(l, leituras[i]);
    printf("antes:  ");
    lista_imprime(l);
    int n = remove_todos(&l, 0);
    printf("depois: ");
    lista_imprime(l);
    printf("%d leituras removidas\n", n);

    No *falhas = lista_insere_inicio(lista_insere_inicio(NULL, 0), 0);
    n = remove_todos(&falhas, 0);
    printf("só falhas: ");
    if (falhas == NULL) printf("NULL");
    printf(" (%d removidas)\n", n);

    lista_libera(l);
    lista_libera(falhas);
    return 0;
}
