// 0154 · Bellman-Ford: pesos negativos
// Exercício E921 · ★★☆

#include <stdio.h>

#define V 7
#define E 10
#define INFINITO 1000000000

typedef struct {
    int de, para, gasto;
} Voo;

const char *pontos[V] = {"Base", "Ponte", "Torre", "Praia", "Farol", "Ilha", "Mata"};
int anterior[V];

void rota(int v) { // recursiva: primeiro o caminho até o anterior, depois v
    if (anterior[v] != -1) {
        rota(anterior[v]);
        printf(" -> ");
    }
    printf("%s", pontos[v]);
}

int main(void) {
    Voo voos[E] = {{0, 1, 10}, {0, 2, 25}, {1, 2, 8}, {2, 3, -5}, {1, 3, 20},
                   {3, 4, 7}, {4, 5, 12}, {2, 5, 30}, {6, 4, 3}, {5, 3, 4}};
    int dist[V];
    for (int v = 0; v < V; v++) {
        dist[v] = INFINITO;
        anterior[v] = -1;
    }
    dist[0] = 0;
    for (int rodada = 1; rodada <= V - 1; rodada++)
        for (int k = 0; k < E; k++) {
            int u = voos[k].de, v = voos[k].para;
            if (dist[u] != INFINITO && dist[u] + voos[k].gasto < dist[v]) {
                dist[v] = dist[u] + voos[k].gasto;
                anterior[v] = u;
            }
        }

    for (int v = 1; v < V; v++) {
        if (dist[v] == INFINITO) {
            printf("%s: inalcançável\n", pontos[v]);
            continue;
        }
        printf("%s (%d%%): ", pontos[v], dist[v]);
        rota(v);
        printf("\n");
    }
    return 0;
}
