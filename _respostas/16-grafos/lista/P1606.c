// Lista · Módulo 16 · Grafos
// Exercício P1606 · ★☆☆ · Quem me segue: o grafo transposto

#include <stdio.h>
#include <stdlib.h>

#define V 5

typedef struct No {
    int v;
    struct No *prox;
} No;

const char *nomes[V] = {"Ana", "Beto", "Cris", "Dani", "Enzo"};

void insere(No *lista[], int u, int v) { // v no começo da lista de u
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) exit(1);
    novo->v = v;
    novo->prox = lista[u];
    lista[u] = novo;
}

void libera(No *lista[]) {
    for (int u = 0; u < V; u++)
        while (lista[u]) {
            No *p = lista[u];
            lista[u] = p->prox;
            free(p);
        }
}

No **transposta(No *lista[]) {
    No **t = calloc(V, sizeof *t); // V cabeças, todas NULL
    if (t == NULL) exit(1);
    for (int u = V - 1; u >= 0; u--) // de trás para frente: listas em ordem crescente
        for (No *p = lista[u]; p; p = p->prox) insere(t, p->v, u); // u -> v vira v -> u
    return t;
}

int main(void) {
    No *segue[V] = {NULL};
    int setas[][2] = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {3, 0}, {3, 2}, {4, 3}};
    for (int k = 6; k >= 0; k--) insere(segue, setas[k][0], setas[k][1]);

    for (int u = 0; u < V; u++) {
        printf("%s segue:", nomes[u]);
        for (No *p = segue[u]; p; p = p->prox) printf(" %s", nomes[p->v]);
        printf("\n");
    }

    No **seguidores = transposta(segue);
    for (int u = 0; u < V; u++) {
        printf("Seguidores de %s:", nomes[u]);
        if (seguidores[u] == NULL) printf(" ninguém");
        for (No *p = seguidores[u]; p; p = p->prox) printf(" %s", nomes[p->v]);
        printf("\n");
    }

    libera(seguidores);
    free(seguidores);
    libera(segue);
    return 0;
}
