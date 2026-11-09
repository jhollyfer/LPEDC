// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2801 · ★☆☆ · A fila do caixa com sentinela

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int senha;
    struct No *ant, *prox;
} No;

typedef struct {
    No nil;
} Lista;

void inicia(Lista *L) {
    L->nil.prox = &L->nil;
    L->nil.ant = &L->nil;
}

void insere_fim(Lista *L, int senha) {
    No *x = malloc(sizeof(No));
    if (x == NULL) {
        exit(1);
    }
    No *y = L->nil.ant; // o último (ou a própria sentinela)
    x->senha = senha;
    x->prox = &L->nil;
    x->ant = y;
    y->prox = x;
    L->nil.ant = x;
}

void mostra(const Lista *L) {
    printf("[");
    for (const No *x = L->nil.prox; x != &L->nil; x = x->prox) {
        printf(" %d", x->senha);
    }
    printf(" ]\n");
}

void mostra_inverso(const Lista *L) {
    printf("[");
    for (const No *x = L->nil.ant; x != &L->nil; x = x->ant) {
        printf(" %d", x->senha);
    }
    printf(" ]\n");
}

void libera(Lista *L) {
    No *x = L->nil.prox;
    while (x != &L->nil) {
        No *seguinte = x->prox;
        free(x);
        x = seguinte;
    }
    inicia(L);
}

int main(void) {
    Lista fila;
    inicia(&fila);
    for (int s = 31; s <= 34; s++) {
        insere_fim(&fila, s);
    }
    printf("ida:   ");
    mostra(&fila);
    printf("volta: ");
    mostra_inverso(&fila);
    libera(&fila);
    printf("vazia: nil aponta para ela mesma? %s\n",
           fila.nil.prox == &fila.nil && fila.nil.ant == &fila.nil ? "sim" : "não");
    return 0;
}
