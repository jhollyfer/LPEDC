// 0114 · Grafos
// Exercício E683 · ★★★

#include <stdio.h>
#include <stdlib.h>

#define V 5

const char *nomes[V] = {"Centro", "Praia", "Feira", "Parque", "Estadio"};
int adj[V][V] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0},
};

typedef struct No {
    int destino;
    struct No *prox;
} No;

int main(void) {
    No *lista[V] = {NULL};
    int alocados = 0;

    for (int i = 0; i < V; i++) {
        // de trás para frente: inserindo no início, a menor fica na frente
        for (int j = V - 1; j >= 0; j--) {
            if (!adj[i][j]) continue;
            No *novo = malloc(sizeof *novo);
            if (novo == NULL) return 1; // (num programa real, liberaria o que já foi alocado)
            novo->destino = j;
            novo->prox = lista[i];
            lista[i] = novo;
            alocados++;
        }
    }

    for (int i = 0; i < V; i++) {
        printf("%-7s ->", nomes[i]);
        for (No *p = lista[i]; p != NULL; p = p->prox) printf(" %s", nomes[p->destino]);
        printf("\n");
    }
    printf("Nós alocados: %d\n", alocados);

    for (int i = 0; i < V; i++) {
        No *p = lista[i];
        while (p != NULL) {
            No *prox = p->prox;
            free(p);
            p = prox;
        }
    }
    return 0;
}
