// lista.c · lista circular simplesmente encadeada

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

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
