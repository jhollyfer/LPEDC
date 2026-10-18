// 0081 · Lista encadeada
// Exercício E483 · ★★☆

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

No *vetor_para_lista(const int v[], int n) {
    No *inicio = NULL;
    for (int i = n - 1; i >= 0; i--) { // de trás para frente
        inicio = lista_insere_inicio(inicio, v[i]);
    }
    return inicio;
}

int lista_para_vetor(const No *inicio, int v[], int max) {
    int i = 0;
    for (const No *p = inicio; p != NULL && i < max; p = p->prox) {
        v[i] = p->valor;
        i++;
    }
    return i;
}

int main(void) {
    int precos[] = {5, 18, 7, 22, 9};
    No *l = vetor_para_lista(precos, 5);
    printf("lista: ");
    lista_imprime(l);

    int volta[10];
    int n = lista_para_vetor(l, volta, 10);
    printf("vetor:");
    for (int i = 0; i < n; i++) printf(" %d", volta[i]);
    printf("\n");

    lista_libera(l);
    return 0;
}
