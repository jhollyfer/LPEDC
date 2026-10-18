// 0080 · Lista circular
// Exercício E480 · ★★★
//
// mostra_escala parava antes de imprimir o último; libera_escala esperava um
// NULL que não existe numa circular e passava por nós já liberados. Na
// circular p nunca vira NULL: o laço daria voltas para sempre.

#include <stdio.h>
#include <stdlib.h>

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

static void mostra_escala(const No *ultimo) {
    printf("escala:");
    const No *p = ultimo->prox;
    do {
        printf(" %d", p->valor);
        p = p->prox;
    } while (p != ultimo->prox);
    printf("\n");
}

static void libera_escala(No *ultimo) {
    No *p = ultimo->prox;
    ultimo->prox = NULL; // corta o círculo
    while (p != NULL) {
        No *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
}

int main(void) {
    No *escala = NULL;
    for (int m = 101; m <= 104; m++) escala = lista_insere_fim(escala, m);
    mostra_escala(escala);
    printf("%d enfermeiros\n", lista_tamanho(escala));
    libera_escala(escala);
    return 0;
}
