// grafo.c · implementação do TAD grafo com listas de adjacência
#include "grafo.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int destino;      // o vizinho
    struct No *prox;  // o próximo vizinho da mesma lista
} No;

struct Grafo {
    int n;       // número de vértices
    No **lista;  // lista[v] aponta para o primeiro vizinho de v
};

Grafo *grafo_criar(int vertices) {
    Grafo *g = malloc(sizeof *g);
    if (g == NULL) return NULL;
    g->n = vertices;
    g->lista = calloc((size_t)vertices, sizeof *g->lista); // todas começam NULL
    if (g->lista == NULL) {
        free(g);
        return NULL;
    }
    return g;
}

bool grafo_ligar(Grafo *g, int origem, int destino) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) return false;
    novo->destino = destino;
    novo->prox = g->lista[origem]; // insere no início: O(1)
    g->lista[origem] = novo;
    return true;
}

int grafo_grau_saida(const Grafo *g, int v) {
    int grau = 0;
    for (No *p = g->lista[v]; p != NULL; p = p->prox) grau++;
    return grau;
}

int grafo_grau_entrada(const Grafo *g, int v) {
    int grau = 0;
    // quem chega em v pode estar em qualquer lista: precisa olhar todas
    for (int u = 0; u < g->n; u++)
        for (No *p = g->lista[u]; p != NULL; p = p->prox)
            if (p->destino == v) grau++;
    return grau;
}

void grafo_mostrar(const Grafo *g, const char *nomes[]) {
    for (int v = 0; v < g->n; v++) {
        printf("%-5s ->", nomes[v]);
        for (No *p = g->lista[v]; p != NULL; p = p->prox) printf(" %s", nomes[p->destino]);
        printf("\n");
    }
}

void grafo_liberar(Grafo *g) {
    if (g == NULL) return;
    for (int v = 0; v < g->n; v++) {
        No *p = g->lista[v];
        while (p != NULL) {
            No *prox = p->prox; // guarda antes de liberar
            free(p);
            p = prox;
        }
    }
    free(g->lista);
    free(g);
}
