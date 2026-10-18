// 0076 · Lista encadeada
// Exercício E454 · ★★☆

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

void imprime_ao_contrario(const No *p) {
    if (p == NULL) return;
    imprime_ao_contrario(p->prox); // primeiro o resto da lista...
    printf(" %d", p->valor);       // ...depois este nó
}

int tamanho_rec(const No *p) {
    if (p == NULL) return 0;
    return 1 + tamanho_rec(p->prox);
}

int main(void) {
    int pix[] = {15, 60, 35, 90, 25};
    No *extrato = NULL;
    for (int i = 0; i < 5; i++) extrato = lista_insere_inicio(extrato, pix[i]);

    printf("mais novo primeiro: ");
    lista_imprime(extrato);
    printf("mais antigo primeiro:");
    imprime_ao_contrario(extrato);
    printf("\n");
    printf("tamanho (recursivo): %d\n", tamanho_rec(extrato));

    lista_libera(extrato);
    return 0;
}
