// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2329 · ★★★ · Johnson em miniatura

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INF 1000000

const char *siglas[V] = {"A", "B", "C", "D", "E"};
int tem[V][V], w[V][V];

void dijkstra(int o, int peso[V][V], int dist[]) {
    bool feito[V] = {false};
    for (int v = 0; v < V; v++) dist[v] = INF;
    dist[o] = 0;
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!feito[v] && dist[v] < INF && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1) break;
        feito[u] = true;
        for (int v = 0; v < V; v++)
            if (tem[u][v] && dist[u] + peso[u][v] < dist[v]) dist[v] = dist[u] + peso[u][v];
    }
}

void floyd(int d[V][V]) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = i == j ? 0 : tem[i][j] ? w[i][j] : INF;
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] < INF && d[k][j] < INF && d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
}

int main(void) {
    int arestas[][3] = {{0, 1, 3}, {1, 2, -2}, {0, 2, 4}, {2, 3, 2}, {3, 1, 1}, {3, 4, -1}, {0, 4, 5}, {4, 2, 3}};
    for (int k = 0; k < 8; k++) {
        tem[arestas[k][0]][arestas[k][1]] = 1;
        w[arestas[k][0]][arestas[k][1]] = arestas[k][2];
    }

    // 1. Bellman-Ford a partir de um vértice novo q, ligado a todos com peso 0:
    //    é o mesmo que começar com h[v] = 0 para todos
    int h[V] = {0};
    for (int r = 1; r <= V; r++)
        for (int u = 0; u < V; u++)
            for (int v = 0; v < V; v++)
                if (tem[u][v] && h[u] + w[u][v] < h[v]) h[v] = h[u] + w[u][v];
    printf("h:");
    for (int v = 0; v < V; v++) printf(" %s=%d", siglas[v], h[v]);
    printf("\n");

    // 2. novos pesos, todos >= 0
    int w2[V][V] = {{0}};
    printf("Pesos novos:");
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            if (tem[u][v]) {
                w2[u][v] = w[u][v] + h[u] - h[v];
                printf(" %s%s=%d", siglas[u], siglas[v], w2[u][v]);
            }
    printf("\n");

    // 3. Dijkstra de cada origem e desfaz a troca de pesos
    int d[V][V], f[V][V];
    for (int o = 0; o < V; o++) {
        int dist[V];
        dijkstra(o, w2, dist);
        for (int v = 0; v < V; v++) d[o][v] = dist[v] >= INF ? INF : dist[v] - h[o] + h[v];
    }
    floyd(f);

    bool iguais = true;
    printf("   ");
    for (int j = 0; j < V; j++) printf(" %3s", siglas[j]);
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%s  ", siglas[i]);
        for (int j = 0; j < V; j++) {
            if (d[i][j] != f[i][j]) iguais = false;
            if (d[i][j] >= INF) printf("   -");
            else printf(" %3d", d[i][j]);
        }
        printf("\n");
    }
    printf("Floyd-Warshall %s\n", iguais ? "confere" : "NÃO confere");
    return 0;
}
