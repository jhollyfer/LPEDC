// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2326 · ★★★ · Onde o ciclo negativo contamina

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 8
#define E 9
#define INF INT_MAX

typedef struct {
    int de, para, custo;
} Portal;

const char *salas[V] = {"Base", "Ponte", "Torre", "Mina", "Vale", "Lago", "Bosque", "Ilha"};
Portal p[E] = {{0, 1, 2}, {1, 2, 3}, {2, 3, -4}, {3, 1, -1}, {3, 4, 2},
               {0, 5, 6}, {5, 6, 1}, {7, 7, -5}, {7, 6, -3}};
bool infinito[V]; // distância -infinito

void espalha(int u) {
    infinito[u] = true;
    for (int i = 0; i < E; i++)
        if (p[i].de == u && !infinito[p[i].para]) espalha(p[i].para);
}

int main(void) {
    int dist[V];
    for (int v = 0; v < V; v++) dist[v] = INF;
    dist[0] = 0;
    for (int r = 1; r <= V - 1; r++)
        for (int i = 0; i < E; i++)
            if (dist[p[i].de] != INF && dist[p[i].de] + p[i].custo < dist[p[i].para])
                dist[p[i].para] = dist[p[i].de] + p[i].custo;

    // rodada extra: quem ainda melhora está num ciclo negativo ou depois dele
    for (int i = 0; i < E; i++)
        if (dist[p[i].de] != INF && dist[p[i].de] + p[i].custo < dist[p[i].para] && !infinito[p[i].para])
            espalha(p[i].para);

    for (int v = 0; v < V; v++) {
        printf("%-6s ", salas[v]);
        if (dist[v] == INF) printf("inalcançável\n");
        else if (infinito[v]) printf("-infinito\n");
        else printf("%d\n", dist[v]);
    }
    return 0;
}
