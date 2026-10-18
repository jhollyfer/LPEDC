// 0154 · Bellman-Ford: pesos negativos
// Exercício E920 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define V 4
#define INFINITO 1000000000

typedef struct {
    int de, para, custo;
} Aresta;

// devolve false se houver ciclo negativo alcançável a partir do vértice 0
bool bellman_ford(const Aresta a[], int e, int dist[]) {
    for (int v = 0; v < V; v++) dist[v] = INFINITO;
    dist[0] = 0;
    for (int rodada = 1; rodada <= V - 1; rodada++)
        for (int k = 0; k < e; k++)
            if (dist[a[k].de] != INFINITO && dist[a[k].de] + a[k].custo < dist[a[k].para])
                dist[a[k].para] = dist[a[k].de] + a[k].custo;
    for (int k = 0; k < e; k++) // rodada extra
        if (dist[a[k].de] != INFINITO && dist[a[k].de] + a[k].custo < dist[a[k].para]) return false;
    return true;
}

void mostra(const char *nome, const Aresta a[], int e) {
    int dist[V];
    printf("%s:", nome);
    if (!bellman_ford(a, e, dist)) {
        printf(" ciclo negativo\n");
        return;
    }
    for (int v = 0; v < V; v++) printf(" %d", dist[v]);
    printf("\n");
}

int main(void) {
    Aresta jogo1[] = {{0, 1, 5}, {1, 2, -3}, {2, 3, 4}, {0, 2, 6}, {3, 1, 1}};
    Aresta jogo2[] = {{0, 1, 5}, {1, 2, -3}, {2, 3, 4}, {0, 2, 6}, {3, 1, -2}};
    mostra("Tabuleiro 1", jogo1, 5);
    mostra("Tabuleiro 2", jogo2, 5);
    return 0;
}
