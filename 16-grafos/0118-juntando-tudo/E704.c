// 0118 · Juntando tudo: a central de entregas
// Exercício E704 · ★☆☆
//
// O programa abaixo roda os três algoritmos do módulo no mesmo grafo
// ponderado não dirigido, sempre a partir de A:
//
//   A-B 1, A-C 4, A-E 9, B-D 2, C-D 1, D-E 3
//
// Sem rodar, preveja as três linhas da saída. Depois rode e confira.
//
// Dicas:
// 1. BFS e DFS ignoram os pesos: olham só se a aresta existe.
// 2. Na DFS, de B você desce para D antes de voltar para C.
// 3. Dijkstra: E tem aresta direta de 9, mas A -> B -> D -> E custa 6.
// 4. Resposta esperada:
//    BFS: A B C E D
//    DFS: A B D C E
//    Dijkstra: A=0 B=1 C=4 D=3 E=6
//
// Escreva sua resposta abaixo (a saída prevista, como comentário):

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5

int peso[V][V];
bool visitado[V];

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
            if (peso[u][v] && !fixo[v] && dist[u] + peso[u][v] < dist[v]) dist[v] = dist[u] + peso[u][v];
    }
    printf("\nDijkstra:");
    for (int v = 0; v < V; v++) printf(" %c=%d", 'A' + v, dist[v]);
    printf("\n");
    return 0;
}
