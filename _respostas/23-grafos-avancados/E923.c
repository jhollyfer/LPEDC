// 0154 · Bellman-Ford: pesos negativos
// Exercício E923 · ★★★

#include <stdio.h>

#define V 5
#define E 5
#define INFINITO 1000000000

typedef struct {
    int de, para, tarifa;
} Trecho;

int main(void) {
    const char *estacoes[V] = {"Centro", "Lapa", "Barra", "Pituba", "Itapuã"};
    Trecho t[E] = {{3, 4, 2}, {2, 3, 3}, {1, 2, -1}, {0, 2, 5}, {0, 1, 4}};
    int dist[V];
    for (int v = 0; v < V; v++) dist[v] = INFINITO;
    dist[0] = 0;

    for (int rodada = 1; rodada <= V - 1; rodada++) // V - 1 rodadas, não V - 2
        for (int k = 0; k < E; k++)
            if (dist[t[k].de] != INFINITO && dist[t[k].de] + t[k].tarifa < dist[t[k].para])
                dist[t[k].para] = dist[t[k].de] + t[k].tarifa;

    for (int k = 0; k < E; k++)
        if (dist[t[k].de] != INFINITO && dist[t[k].de] + t[k].tarifa < dist[t[k].para]) {
            printf("Ciclo negativo!\n");
            return 0;
        }
    for (int v = 0; v < V; v++) printf("%s: R$ %d\n", estacoes[v], dist[v]);
    return 0;
}
