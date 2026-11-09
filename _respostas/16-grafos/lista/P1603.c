// Lista · Módulo 16 · Grafos
// Exercício P1603 · ★☆☆ · Da lista para a matriz: o cadastro torto

#include <stdio.h>
#include <stdlib.h>

#define V 5

typedef struct No {
    int v;
    struct No *prox;
} No;

const char *nomes[V] = {"Ana", "Bruno", "Carla", "Davi", "Eva"};

void insere(No *lista[], int u, int v) { // põe v no começo da lista de u
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) exit(1);
    novo->v = v;
    novo->prox = lista[u];
    lista[u] = novo;
}

void lista_para_matriz(No *lista[], int m[V][V]) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) m[i][j] = 0; // O(V²): a matriz cobra isso sempre
    for (int u = 0; u < V; u++)
        for (No *p = lista[u]; p != NULL; p = p->prox) m[u][p->v] = 1; // O(V + E)
}

int confere_simetria(int m[V][V]) {
    int tortos = 0;
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            if (m[i][j] != m[j][i]) {
                printf("Torto: %s e %s\n", nomes[i], nomes[j]);
                tortos++;
            }
    return tortos;
}

int main(void) {
    No *lista[V] = {NULL};
    int amizades[][2] = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {1, 4}};
    for (int k = 0; k < 5; k++) {
        insere(lista, amizades[k][0], amizades[k][1]);
        insere(lista, amizades[k][1], amizades[k][0]);
    }
    insere(lista, 3, 4); // o cadastro torto: só Davi -> Eva

    int m[V][V];
    lista_para_matriz(lista, m);
    printf("       A B C D E\n");
    for (int i = 0; i < V; i++) {
        printf("%-6s", nomes[i]);
        for (int j = 0; j < V; j++) printf(" %d", m[i][j]);
        printf("\n");
    }
    printf("Pares tortos: %d\n", confere_simetria(m));

    for (int u = 0; u < V; u++)
        while (lista[u]) {
            No *p = lista[u];
            lista[u] = p->prox;
            free(p);
        }
    return 0;
}
