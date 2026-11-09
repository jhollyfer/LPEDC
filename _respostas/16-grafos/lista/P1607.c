// Lista · Módulo 16 · Grafos
// Exercício P1607 · ★☆☆ · BFS a partir da rodoviária: d e π

#include <stdio.h>

#define V 8

const char *nomes[V] = {"Flores", "Parque Dez", "Aleixo", "Centro",
                        "Educandos", "Cachoeirinha", "Japiim", "Coroado"};
int adj[V][V] = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 0, 1, 0, 1, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 1, 0, 0, 0, 1, 0},
};

void bfs(int s, int d[], int pi[]) {
    int fila[V], ini = 0, fim = 0; // cada vértice entra uma vez: V posições bastam
    for (int v = 0; v < V; v++) d[v] = pi[v] = -1;
    d[s] = 0;
    fila[fim++] = s;
    printf("Saem da fila:");
    while (ini < fim) {
        int u = fila[ini++];
        printf(" %s", nomes[u]);
        for (int v = 0; v < V; v++)
            if (adj[u][v] && d[v] == -1) { // vizinho ainda branco
                d[v] = d[u] + 1;
                pi[v] = u;
                fila[fim++] = v;
            }
    }
    printf("\n");
}

int main(void) {
    int d[V], pi[V];
    bfs(0, d, pi);
    printf("%-13s d  pi\n", "bairro");
    for (int v = 0; v < V; v++)
        printf("%-13s %d  %s\n", nomes[v], d[v], pi[v] == -1 ? "NIL" : nomes[pi[v]]);
    return 0;
}
