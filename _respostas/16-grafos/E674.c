// 0113 · Juntando tudo: a central de entregas
// Exercício E674 · ★☆☆

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5

int peso[V][V];
bool visitado[V];

// mostra a rota guardada em pai[] (de trás para frente) e soma os pesos
void mostrar_rota(const int pai[], int destino) {
    int rota[V], n = 0, total = 0;
    for (int v = destino; v != -1; v = pai[v]) rota[n++] = v;
    for (int i = n - 1; i >= 0; i--) {
        printf("%c%s", 'A' + rota[i], i > 0 ? " -> " : "");
        if (i > 0) total += peso[rota[i]][rota[i - 1]];
    }
    printf(" (%d)\n", total);
}

void dfs(int u) {
    visitado[u] = true;
    printf(" %c", 'A' + u);
    for (int v = 0; v < V; v++)
        if (peso[u][v] && !visitado[v]) dfs(v);
}

int main(void) {
    int arestas[][3] = {{0, 1, 1}, {0, 2, 4}, {0, 4, 9}, {1, 3, 2}, {2, 3, 1}, {3, 4, 3}};
    for (int k = 0; k < 6; k++) {
        peso[arestas[k][0]][arestas[k][1]] = arestas[k][2];
        peso[arestas[k][1]][arestas[k][0]] = arestas[k][2];
    }

    int pai_bfs[V], pai_dij[V];
    for (int v = 0; v < V; v++) pai_bfs[v] = pai_dij[v] = -1;

    // BFS
    bool visto[V] = {true};
    int fila[V], inicio = 0, fim = 0;
    fila[fim++] = 0;
    printf("BFS:");
    while (inicio < fim) {
        int u = fila[inicio++];
        printf(" %c", 'A' + u);
        for (int v = 0; v < V; v++)
            if (peso[u][v] && !visto[v]) {
                visto[v] = true;
                pai_bfs[v] = u;
                fila[fim++] = v;
            }
    }

    printf("\nDFS:");
    dfs(0);

    // Dijkstra
    int dist[V];
    bool fixo[V] = {false};
    for (int v = 0; v < V; v++) dist[v] = INT_MAX;
    dist[0] = 0;
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!fixo[v] && dist[v] != INT_MAX && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1) break;
        fixo[u] = true;
        for (int v = 0; v < V; v++)
            if (peso[u][v] && !fixo[v] && dist[u] + peso[u][v] < dist[v]) {
                dist[v] = dist[u] + peso[u][v];
                pai_dij[v] = u;
            }
    }
    printf("\nDijkstra:");
    for (int v = 0; v < V; v++) printf(" %c=%d", 'A' + v, dist[v]);
    printf("\n");
    printf("Menos arestas até E: ");
    mostrar_rota(pai_bfs, 4);
    printf("Menos peso até E: ");
    mostrar_rota(pai_dij, 4);
    return 0;
}
