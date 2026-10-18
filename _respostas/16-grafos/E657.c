// 0110 · BFS: busca em largura
// Exercício E657 · ★★☆
//
// Por que passa pelo Centro: como vizinhos da Lapa, Centro (0) é examinado
// antes de Penha (3) e entra antes na fila. Ao sair, o Centro descobre Moema
// (dist 2); quando a Penha sai, Moema já tem dono. Moema sai antes de
// Tatuape e descobre a Saude. Os dois caminhos têm 3 ônibus; a ordem dos
// índices decide o empate.

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

int main(void) {
    int origem = 1, destino = 4; // Lapa -> Saude
    int dist[V], pai[V], fila[V], inicio = 0, fim = 0;
    for (int v = 0; v < V; v++) {
        dist[v] = -1;
        pai[v] = -1;
    }
    dist[origem] = 0;
    fila[fim++] = origem;
    while (inicio < fim) {
        int u = fila[inicio++];
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                pai[v] = u;
                fila[fim++] = v;
            }
        }
    }

    imprimir_caminho(pai, destino);
    printf("\nÔnibus: %d\n", dist[destino]);
    return 0;
}
