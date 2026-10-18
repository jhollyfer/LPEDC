// 0079 · Lista dupla
// Exercício E470 · ★☆☆
//
// Resposta:
//   4 <-> 2 <-> 1 <-> 3     fim(1), início(2), fim(3), início(4)
//   3 <-> 1 <-> 2 <-> 4     o mesmo caminho, seguindo os ant
//   2 2                     inicio->prox é o 2; fim->ant->ant: 3 -> 1 -> 2
//   2 3                     os vizinhos do 1
//   2: 2 <-> 1              saíram o 4 (primeiro) e o 3 (último)
//   1 <-> 2
//   1                       as pontas novas têm ant e prox NULL

#include <stdio.h>
// ---- lista.h e lista.c colados aqui, para esta resolução rodar sozinha ----
// lista.h · lista duplamente encadeada de inteiros
//
// Cada nó conhece o anterior e o próximo. A lista guarda as duas pontas
// (inicio e fim) e o tamanho, numa struct que pode morar no main:
//   Lista trem;
//   lista_inicia(&trem);

#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef struct no {
    int valor;
    struct no *ant;  // o anterior, ou NULL no primeiro
    struct no *prox; // o próximo, ou NULL no último
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

// deixa a lista vazia (chame antes de usar)
void lista_inicia(Lista *l);

// põe "valor" na frente / atrás; false se faltar memória
bool lista_insere_inicio(Lista *l, int valor);
bool lista_insere_fim(Lista *l, int valor);

// devolve o primeiro nó com "valor", ou NULL
No *lista_busca(const Lista *l, int valor);

// tira o nó p (que precisa estar na lista) e devolve a memória dele: O(1)
void lista_remove_no(Lista *l, No *p);

// mostra do início para o fim / do fim para o início: 98 <-> 105 <-> 87
void lista_imprime(const Lista *l);
void lista_imprime_reverso(const Lista *l);

// devolve a memória de todos os nós e deixa a lista vazia
void lista_libera(Lista *l);

#endif

// lista.c · lista duplamente encadeada de inteiros

#include <stdio.h>
#include <stdlib.h>

void lista_inicia(Lista *l) {
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;
}

static No *cria_no(int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) return NULL;
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

bool lista_insere_inicio(Lista *l, int valor) {
    No *novo = cria_no(valor);
    if (novo == NULL) return false;
    novo->prox = l->inicio;
    if (l->inicio != NULL) {
        l->inicio->ant = novo; // o antigo primeiro ganha um anterior
    } else {
        l->fim = novo;         // lista vazia: o novo também é o último
    }
    l->inicio = novo;
    l->tamanho++;
    return true;
}

bool lista_insere_fim(Lista *l, int valor) {
    No *novo = cria_no(valor);
    if (novo == NULL) return false;
    novo->ant = l->fim;
    if (l->fim != NULL) {
        l->fim->prox = novo;   // o antigo último ganha um próximo
    } else {
        l->inicio = novo;      // lista vazia: o novo também é o primeiro
    }
    l->fim = novo;
    l->tamanho++;
    return true;
}

No *lista_busca(const Lista *l, int valor) {
    No *p = l->inicio;
    while (p != NULL && p->valor != valor) p = p->prox;
    return p;
}

void lista_remove_no(Lista *l, No *p) {
    if (p->ant == NULL) l->inicio = p->prox;  // era o primeiro
    else p->ant->prox = p->prox;              // o anterior pula o p
    if (p->prox == NULL) l->fim = p->ant;     // era o último
    else p->prox->ant = p->ant;               // o seguinte pula o p para trás
    free(p);
    l->tamanho--;
}

void lista_imprime(const Lista *l) {
    if (l->inicio == NULL) {
        printf("(vazia)\n");
        return;
    }
    for (const No *p = l->inicio; p != NULL; p = p->prox) {
        printf(p->prox != NULL ? "%d <-> " : "%d\n", p->valor);
    }
}

void lista_imprime_reverso(const Lista *l) {
    if (l->fim == NULL) {
        printf("(vazia)\n");
        return;
    }
    for (const No *p = l->fim; p != NULL; p = p->ant) {
        printf(p->ant != NULL ? "%d <-> " : "%d\n", p->valor);
    }
}

void lista_libera(Lista *l) {
    No *p = l->inicio;
    while (p != NULL) {
        No *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
    lista_inicia(l);
}
// ---- fim de lista.h e lista.c ----

int main(void) {
    Lista l;
    lista_inicia(&l);
    lista_insere_fim(&l, 1);
    lista_insere_inicio(&l, 2);
    lista_insere_fim(&l, 3);
    lista_insere_inicio(&l, 4);
    lista_imprime(&l);
    lista_imprime_reverso(&l);

    printf("%d %d\n", l.inicio->prox->valor, l.fim->ant->ant->valor);
    No *p = lista_busca(&l, 1);
    printf("%d %d\n", p->ant->valor, p->prox->valor);

    lista_remove_no(&l, l.inicio);
    lista_remove_no(&l, l.fim);
    printf("%d: ", l.tamanho);
    lista_imprime(&l);
    lista_imprime_reverso(&l);
    printf("%d\n", l.inicio->ant == NULL && l.fim->prox == NULL);

    lista_libera(&l);
    return 0;
}
