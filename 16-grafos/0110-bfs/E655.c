// 0110 · BFS: busca em largura
// Exercício E655 · ★☆☆
//
// O mapa abaixo liga seis bairros por linhas de ônibus diretas (grafo não
// dirigido). O programa roda uma BFS a partir da Penha. Sem rodar, preveja a
// ordem em que os bairros são visitados e a distância de cada um. Faça a
// tabela da fila no papel. Depois rode e confira.
//
// Dicas:
// 1. Os vizinhos são examinados em ordem de índice (v de 0 a 5).
// 2. A Penha (3) é vizinha de Lapa (1), Moema (2) e Tatuape (5): os três
//    entram na fila nessa ordem, todos com distância 1.
// 3. Resposta esperada:
//    Penha(0) Lapa(1) Moema(1) Tatuape(1) Centro(2) Saude(2)
//
// Escreva sua resposta abaixo (a saída prevista, como comentário):

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
    int dist[V], fila[V], inicio = 0, fim = 0;
    for (int v = 0; v < V; v++) dist[v] = -1;

    dist[3] = 0;
    fila[fim++] = 3;
    while (inicio < fim) {
        int u = fila[inicio++];
        printf("%s(%d) ", nomes[u], dist[u]);
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                fila[fim++] = v;
            }
        }
    }
    printf("\n");
    return 0;
}
