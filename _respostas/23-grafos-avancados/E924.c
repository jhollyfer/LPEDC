// 0154 · Bellman-Ford: pesos negativos
// Exercício E924 · ★★★

#include <stdio.h>

#define V 5
#define E 8
#define INFINITO 1000000000

typedef struct {
    int de, para, preco;
} Voo;

Voo voos[E] = {{0, 4, 900}, {0, 1, 200}, {1, 2, 250}, {2, 4, 300},
               {0, 2, 500}, {1, 3, 350}, {3, 4, 150}, {2, 3, 120}};

// Bellman-Ford limitado: depois da rodada r, dist[v] é o melhor preço com até r voos
int mais_barato(int origem, int destino, int k) {
    int dist[V], antes[V];
    for (int v = 0; v < V; v++) dist[v] = INFINITO;
    dist[origem] = 0;
    for (int r = 1; r <= k; r++) {
        for (int v = 0; v < V; v++) antes[v] = dist[v]; // a foto da rodada anterior
        for (int i = 0; i < E; i++) {
            int u = voos[i].de, v = voos[i].para;
            if (antes[u] != INFINITO && antes[u] + voos[i].preco < dist[v])
                dist[v] = antes[u] + voos[i].preco; // lê a foto, escreve no novo
        }
    }
    return dist[destino];
}

int main(void) {
    for (int k = 1; k <= 3; k++) printf("Até %d trecho%s: R$ %d\n", k, k > 1 ? "s" : "", mais_barato(0, 4, k));
    return 0;
}
