// 0077 · Busca e remoção
// Exercício E461 · ★★★
//
// Os quatro erros: (1) free(p) antes de usar p->prox; (2) ant->prox com ant
// NULL quando o removido é o primeiro; (3) o início chegava por valor, então
// o main nunca via o início novo; (4) "p->valor != valor && p != NULL" lia
// p->valor antes de saber se p era NULL.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

static bool tira(No **inicio, int valor) {
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

int main(void) {
    No *lista = NULL;
    int codigos[] = {9, 27, 3, 14};
    for (int i = 0; i < 4; i++) lista = lista_insere_inicio(lista, codigos[i]);
    lista_imprime(lista);

    tira(&lista, 27);
    tira(&lista, 14);
    lista_imprime(lista);
    if (!tira(&lista, 50)) printf("50 não estava na lista\n");

    lista_libera(lista);
    return 0;
}
