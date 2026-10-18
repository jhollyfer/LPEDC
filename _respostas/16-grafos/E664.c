// 0111 · DFS: busca em profundidade
// Exercício E664 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *nomes[V] = {"Lógica", "C", "Ponteiros", "Estruturas", "Grafos", "Discreta"};
int adj[V][V];
bool visitado[V];
int termino[V], n_termino = 0;

void dfs(int u) {
    visitado[u] = true;
    for (int v = 0; v < V; v++)
        if (adj[u][v] && !visitado[v]) dfs(v);
    termino[n_termino++] = u; // pós-ordem: só depois de todos os sucessores
}

int main(void) {
    int pre[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {5, 4}, {0, 5}};
    for (int k = 0; k < 6; k++) adj[pre[k][0]][pre[k][1]] = 1;

    for (int s = 0; s < V; s++)
        if (!visitado[s]) dfs(s);

    printf("Ordem de término:");
    for (int i = 0; i < n_termino; i++) printf(" %s", nomes[termino[i]]);
    printf("\nOrdem para cursar:");
    for (int i = n_termino - 1; i >= 0; i--) printf(" %s", nomes[termino[i]]);
    printf("\n");
    return 0;
}
