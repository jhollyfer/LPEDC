// Lista · Módulo 16 · Grafos
// Exercício P1608 · ★☆☆ · Conserte a BFS das trilhas do bosque

#include <stdio.h>

#define V 7

const char *nomes[V] = {"Entrada", "Lago", "Viveiro", "Mirante", "Orquidario", "Torre", "Cafe"};
int adj[V][V] = {
    {0, 1, 1, 0, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 1},
    {0, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 1, 0, 0},
};

int main(void) {
    int d[V], pi[V], fila[V], ini = 0, fim = 0;
    for (int v = 0; v < V; v++) d[v] = pi[v] = -1;
    d[0] = 0;
    fila[fim++] = 0;
    while (ini < fim) {
        int u = fila[ini++]; // erro 1: tirava do fim (pilha); fila tira do começo
        for (int v = 0; v < V; v++)
            if (adj[u][v] && d[v] == -1) {
                d[v] = d[u] + 1;
                pi[v] = u; // erro 2: o predecessor é quem descobriu v
                fila[fim++] = v;
            }
    }
    for (int v = 0; v < V; v++)
        printf("%-10s d=%d  pi=%s\n", nomes[v], d[v], pi[v] == -1 ? "NIL" : nomes[pi[v]]);
    return 0;
}
