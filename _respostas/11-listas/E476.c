// 0080 · Lista circular
// Exercício E476 · ★☆☆
//
// Resposta:
//   5 -> 10 -> 20 -> 30 -> (volta ao 5)   o 5 entrou na frente; u está no 30
//   30 5                                  o último e o primeiro (u->prox)
//   10 20 30 5 10 20                      depois do 30 vem o 5 de novo
//   20 -> 30 -> 5 -> 10 -> (volta ao 20)  u andou dois: agora o último é o 10
//   20 -> 30 -> 5 -> (volta ao 20)        tirou o último; o 5 assume
//   3

#include <stdio.h>
// ---- lista.h e lista.c colados aqui, para esta resolução rodar sozinha ----
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

// lista.c · lista circular simplesmente encadeada

#include <stdio.h>
#include <stdlib.h>

static No *cria_no(int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = novo; // sozinho, ele é o próprio círculo
    return novo;
}

No *lista_insere_inicio(No *ultimo, int valor) {
    No *novo = cria_no(valor);
    if (ultimo == NULL) return novo; // único nó: primeiro e último
    novo->prox = ultimo->prox;       // o novo aponta para o antigo primeiro
    ultimo->prox = novo;             // o último fecha o círculo no novo
    return ultimo;
}

No *lista_insere_fim(No *ultimo, int valor) {
    // inserir no fim = inserir no início e dizer que o novo é o último
    ultimo = lista_insere_inicio(ultimo, valor);
    return ultimo->prox;
}

bool lista_remove(No **ultimo, int valor) {
    if (*ultimo == NULL) return false;
    No *ant = *ultimo;
    No *p = (*ultimo)->prox;      // começa no primeiro
    while (p->valor != valor) {
        if (p == *ultimo) return false; // deu a volta inteira
        ant = p;
        p = p->prox;
    }
    if (p == ant) {
        *ultimo = NULL;           // era o único nó
    } else {
        ant->prox = p->prox;
        if (p == *ultimo) *ultimo = ant; // tirou o último: o anterior assume
    }
    free(p);
    return true;
}

void lista_imprime(const No *ultimo) {
    if (ultimo == NULL) {
        printf("(vazia)\n");
        return;
    }
    const No *p = ultimo->prox;
    do {                          // do-while: o primeiro passo é de graça
        printf("%d -> ", p->valor);
        p = p->prox;
    } while (p != ultimo->prox);  // parou quando voltou ao primeiro
    printf("(volta ao %d)\n", ultimo->prox->valor);
}

int lista_tamanho(const No *ultimo) {
    if (ultimo == NULL) return 0;
    int n = 0;
    const No *p = ultimo;
    do {
        n++;
        p = p->prox;
    } while (p != ultimo);
    return n;
}

void lista_libera(No *ultimo) {
    if (ultimo == NULL) return;
    No *p = ultimo->prox;
    ultimo->prox = NULL;          // corta o círculo: vira uma lista comum
    while (p != NULL) {
        No *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
}
// ---- fim de lista.h e lista.c ----

int main(void) {
    No *u = NULL;
    u = lista_insere_fim(u, 10);
    u = lista_insere_fim(u, 20);
    u = lista_insere_inicio(u, 5);
    u = lista_insere_fim(u, 30);
    lista_imprime(u);
    printf("%d %d\n", u->valor, u->prox->valor);

    const No *p = u->prox->prox;
    for (int i = 0; i < 6; i++) {
        printf(i == 0 ? "%d" : " %d", p->valor);
        p = p->prox;
    }
    printf("\n");

    u = u->prox->prox;
    lista_imprime(u);
    lista_remove(&u, 10);
    lista_imprime(u);
    printf("%d\n", lista_tamanho(u));

    lista_libera(u);
    return 0;
}
