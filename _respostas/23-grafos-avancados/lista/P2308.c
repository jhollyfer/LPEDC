// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2308 · ★☆☆ · Bellman-Ford rodada a rodada

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define E 7
#define INF INT_MAX

typedef struct {
    int de, para, custo;
} Trecho;

const char *pontos[V] = {"Casa", "Shopping", "Terminal", "Faculdade", "Estágio"};

void mostra(int rodada, const int dist[]) {
    printf("rodada %d:", rodada);
    for (int v = 0; v < V; v++) {
        if (dist[v] == INF) printf("   -");
        else printf(" %3d", dist[v]);
    }
    printf("\n");
}

int main(void) {
    // a lista vem nesta ordem, de propósito a pior para o algoritmo
    Trecho t[E] = {{3, 4, 3}, {1, 3, 4}, {1, 4, 10}, {2, 1, -2}, {2, 3, 9}, {0, 1, 8}, {0, 2, 5}};
    int dist[V];
    for (int v = 0; v < V; v++) dist[v] = INF;
    dist[0] = 0;
    mostra(0, dist);

    int rodada = 1;
    for (; rodada <= V - 1; rodada++) {
        bool mudou = false;
        for (int i = 0; i < E; i++) {
            if (dist[t[i].de] == INF) continue;
            int nova = dist[t[i].de] + t[i].custo;
            if (nova < dist[t[i].para]) {
                dist[t[i].para] = nova;
                mudou = true;
            }
        }
        if (!mudou) {
            printf("rodada %d: nada mudou, para aqui\n", rodada);
            break;
        }
        mostra(rodada, dist);
    }
    return 0;
}
