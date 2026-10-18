// 0110 · BFS: busca em largura
// Exercício E655 · ★☆☆

#include <stdio.h>

#define V 6

int main(void) {
    const char *nomes[V] = {"Centro", "Lapa", "Moema", "Penha", "Saude", "Tatuape"};
    int adj[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {0, 1, 1, 0, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 0},
    };
    int dist[V], pai[V], fila[V], inicio = 0, fim = 0;
    for (int v = 0; v < V; v++) {
        dist[v] = -1;
        pai[v] = -1;
    }

    dist[3] = 0;
    fila[fim++] = 3;
    while (inicio < fim) {
        int u = fila[inicio++];
        printf("%s(%d) ", nomes[u], dist[u]);
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                pai[v] = u; // quem descobriu v
                fila[fim++] = v;
            }
        }
    }
    printf("\n");

    for (int v = 0; v < V; v++) {
        if (pai[v] == -1) printf("%s: origem\n", nomes[v]);
        else printf("%s: descoberto por %s\n", nomes[v], nomes[pai[v]]);
    }
    return 0;
}
