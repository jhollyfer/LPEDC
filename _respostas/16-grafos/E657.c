// 0110 · BFS: busca em largura
// Exercício E657 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *nomes[V] = {"Centro", "Lapa", "Moema", "Penha", "Saude", "Tatuape"};
int adj[V][V] = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 1},
    {0, 0, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 0},
};

void imprimir_caminho(const int pai[], int v) {
    if (pai[v] != -1) {
        imprimir_caminho(pai, pai[v]); // primeiro o caminho até o pai
        printf(" -> ");
    }
    printf("%s", nomes[v]);
}

// BFS que examina os vizinhos em ordem crescente ou decrescente de índice
void bfs(int origem, int dist[], int pai[], bool crescente) {
    int fila[V], inicio = 0, fim = 0;
    for (int v = 0; v < V; v++) {
        dist[v] = -1;
        pai[v] = -1;
    }
    dist[origem] = 0;
    fila[fim++] = origem;
    while (inicio < fim) {
        int u = fila[inicio++];
        for (int k = 0; k < V; k++) {
            int v = crescente ? k : V - 1 - k;
            if (adj[u][v] && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                pai[v] = u;
                fila[fim++] = v;
            }
        }
    }
}

int main(void) {
    int origem = 1, destino = 4; // Lapa -> Saude
    int dist[V], pai[V];

    bfs(origem, dist, pai, true);
    imprimir_caminho(pai, destino);
    printf("\nÔnibus: %d\n", dist[destino]);

    bfs(origem, dist, pai, false);
    printf("Ao contrário: ");
    imprimir_caminho(pai, destino);
    printf("\nÔnibus: %d\n", dist[destino]);
    return 0;
}
