// Lista · Módulo 11 · Listas
// Exercício P1126 · ★★★ · Lista encadeada sem malloc (cursores)

#include <stdbool.h>
#include <stdio.h>

#define CAP 6

typedef struct {
    int valor;
    int prox; // índice da próxima célula, ou -1
} Celula;

typedef struct {
    Celula c[CAP];
    int inicio; // primeira célula da lista, ou -1
    int livre;  // primeira célula livre, ou -1
} Estatica;

void inicializa(Estatica *l) {
    l->inicio = -1;
    l->livre = 0;
    for (int i = 0; i < CAP; i++) {
        l->c[i].valor = 0;
        l->c[i].prox = i + 1 < CAP ? i + 1 : -1;
    }
}

bool insere_ordenado(Estatica *l, int x) {
    if (l->livre == -1) {
        return false;
    }
    int novo = l->livre; // tira da lista de livres
    l->livre = l->c[novo].prox;
    l->c[novo].valor = x;
    if (l->inicio == -1 || x < l->c[l->inicio].valor) {
        l->c[novo].prox = l->inicio;
        l->inicio = novo;
        return true;
    }
    int p = l->inicio;
    while (l->c[p].prox != -1 && l->c[l->c[p].prox].valor < x) {
        p = l->c[p].prox;
    }
    l->c[novo].prox = l->c[p].prox;
    l->c[p].prox = novo;
    return true;
}

bool remove_valor(Estatica *l, int x) {
    int ant = -1, p = l->inicio;
    while (p != -1 && l->c[p].valor != x) {
        ant = p;
        p = l->c[p].prox;
    }
    if (p == -1) {
        return false;
    }
    if (ant == -1) {
        l->inicio = l->c[p].prox;
    } else {
        l->c[ant].prox = l->c[p].prox;
    }
    l->c[p].prox = l->livre; // devolve para os livres
    l->livre = p;
    return true;
}

void mostra(const Estatica *l) {
    printf("lista:");
    for (int p = l->inicio; p != -1; p = l->c[p].prox) {
        printf(" %d", l->c[p].valor);
    }
    printf(" | início %d, livre %d\n", l->inicio, l->livre);
}

int main(void) {
    Estatica l;
    inicializa(&l);
    insere_ordenado(&l, 30);
    insere_ordenado(&l, 10);
    insere_ordenado(&l, 20);
    mostra(&l);
    remove_valor(&l, 10);
    mostra(&l);
    int mais[4] = {25, 5, 40, 50};
    for (int i = 0; i < 4; i++) {
        insere_ordenado(&l, mais[i]);
    }
    mostra(&l);
    if (!insere_ordenado(&l, 60)) {
        printf("60: sem célula livre\n");
    }
    for (int i = 0; i < CAP; i++) {
        printf("célula %d: %d -> %d\n", i, l.c[i].valor, l.c[i].prox);
    }
    return 0;
}
