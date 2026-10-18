// 0076 · Lista encadeada
// Exercício E452 · ★☆☆
//
// Resposta:
//   12                          o último inserido (4 * 3) fica na frente
//   6                           12 -> 9 -> 6: dois prox a partir do primeiro
//   3                           o laço para no nó cujo prox é NULL: o último
//   99 -> 9 -> 6 -> 3 -> NULL   o 99 aponta para l->prox, que é o 9
//   12 -> 9 -> 6 -> 3 -> NULL   l não mudou
//
// As duas listas compartilham a cauda 9 -> 6 -> 3. lista_libera(outra)
// liberaria esses três nós, e lista_libera(l) tentaria liberá-los de novo:
// free duplo. Por isso só o nó 99, que é só de "outra", sai com free(outra).

#include <stdio.h>
#include <stdlib.h>
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
    printf("%d\n", l->valor);
    printf("%d\n", l->prox->prox->valor);

    No *p = l;
    while (p->prox != NULL) {
        p = p->prox;
    }
    printf("%d\n", p->valor);

    No *outra = lista_insere_inicio(l->prox, 99);
    lista_imprime(outra);
    lista_imprime(l);

    free(outra);
    lista_libera(l);
    return 0;
}
