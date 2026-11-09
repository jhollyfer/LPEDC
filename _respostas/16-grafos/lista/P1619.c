// Lista · Módulo 16 · Grafos
// Exercício P1619 · ★★☆ · Instrumente: a BFS na matriz e na lista

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct No {
    int v;
    struct No *prox;
} No;

unsigned char adj[MAX][MAX];
long consultas;

int bfs_matriz(int n, int s, int t) {
    static int d[MAX], fila[MAX];
    int ini = 0, fim = 0;
    for (int v = 0; v < n; v++) d[v] = -1;
    d[s] = 0;
    fila[fim++] = s;
    while (ini < fim) {
        int u = fila[ini++];
        for (int v = 0; v < n; v++) {
            consultas++; // olhou adj[u][v]
            if (adj[u][v] && d[v] == -1) {
                d[v] = d[u] + 1;
                fila[fim++] = v;
            }
        }
    }
    return d[t];
}

int bfs_lista(No *lista[], int n, int s, int t) {
    static int d[MAX], fila[MAX];
    int ini = 0, fim = 0;
    for (int v = 0; v < n; v++) d[v] = -1;
    d[s] = 0;
    fila[fim++] = s;
    while (ini < fim) {
        int u = fila[ini++];
        for (No *p = lista[u]; p; p = p->prox) {
            consultas++; // visitou um nó da lista
            if (d[p->v] == -1) {
                d[p->v] = d[u] + 1;
                fila[fim++] = p->v;
            }
        }
    }
    return d[t];
}

void insere(No *lista[], int u, int v) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) exit(1);
    novo->v = v;
    novo->prox = lista[u];
    lista[u] = novo;
}

int main(void) {
    static No *lista[MAX];
    int tamanhos[] = {10, 100, 1000};
    for (int k = 0; k < 3; k++) {
        int n = tamanhos[k];
        for (int i = 0; i < n; i++) {
            lista[i] = NULL;
            for (int j = 0; j < n; j++) adj[i][j] = 0;
        }
        for (int i = 0; i + 1 < n; i++) {
            adj[i][i + 1] = adj[i + 1][i] = 1;
            insere(lista, i, i + 1);
            insere(lista, i + 1, i);
        }
        consultas = 0;
        int dm = bfs_matriz(n, 0, n - 1);
        long cm = consultas;
        consultas = 0;
        int dl = bfs_lista(lista, n, 0, n - 1);
        printf("n = %4d: matriz d = %3d, %7ld consultas | lista d = %3d, %4ld consultas\n",
               n, dm, cm, dl, consultas);
        for (int i = 0; i < n; i++)
            while (lista[i]) {
                No *p = lista[i];
                lista[i] = p->prox;
                free(p);
            }
    }
    return 0;
}
