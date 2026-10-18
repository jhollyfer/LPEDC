// 0111 · DFS: busca em profundidade
// Exercício E662 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define V 5

const char *nomes[V] = {"Casa", "Mercado", "Escola", "Hospital", "Praça"};
int adj[V][V];
bool visitado[V];

void dfs(int u) {
    visitado[u] = true;
    printf(" %s", nomes[u]);
    for (int v = 0; v < V; v++)
        if (adj[u][v] && !visitado[v]) dfs(v);
}

void buscar_de(int origem) {
    for (int v = 0; v < V; v++) visitado[v] = false;
    printf("De %s:", nomes[origem]);
    dfs(origem);
    printf("\n");
}

int main(void) {
    int ruas[][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 4}, {3, 1}};
    for (int k = 0; k < 5; k++) adj[ruas[k][0]][ruas[k][1]] = 1; // só num sentido

    buscar_de(0);
    bool casa_hospital = visitado[3]; // visitado ainda é o da busca da Casa
    buscar_de(3);
    printf("Casa chega no Hospital? %s\n", casa_hospital ? "sim" : "não");
    return 0;
}
