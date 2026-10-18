// 0154 · Bellman-Ford: pesos negativos
// Exercício E919 · ★☆☆

#include <stdio.h>

#define V 5
#define E 7
#define INFINITO 1000000000

typedef struct {
    int de, para, custo;
} Trecho;

int main(void) {
    const char *lugares[V] = {"Garagem", "Posto A", "Posto B", "Pedágio", "Sítio"};
    Trecho t[E] = {{0, 1, 30}, {0, 2, 45}, {1, 2, -10}, {1, 3, 25},
                   {2, 3, 12}, {3, 4, 8}, {2, 4, 40}};
    int dist[V];
    for (int v = 0; v < V; v++) dist[v] = INFINITO;
    dist[0] = 0;
    for (int rodada = 1; rodada <= V - 1; rodada++)
        for (int k = 0; k < E; k++)
            if (dist[t[k].de] != INFINITO && dist[t[k].de] + t[k].custo < dist[t[k].para])
                dist[t[k].para] = dist[t[k].de] + t[k].custo;
    for (int v = 0; v < V; v++) printf("%s: R$ %d\n", lugares[v], dist[v]);
    return 0;
}
