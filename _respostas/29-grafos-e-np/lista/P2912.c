// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2912 · ★★☆ · Trajeto euleriano dirigido

#include <stdio.h>

#define V 5
#define E 6

int trecho[V][V];

int main(void) {
    int t[E][2] = {{0, 1}, {1, 2}, {2, 0}, {0, 3}, {3, 1}, {1, 4}};
    int saldo[V] = {0};
    for (int k = 0; k < E; k++) trecho[t[k][0]][t[k][1]]++, saldo[t[k][0]]++, saldo[t[k][1]]--;
    int ini = 0;
    for (int u = 0; u < V; u++) {
        printf("Porto %d: saída - entrada = %d\n", u, saldo[u]);
        if (saldo[u] == 1) ini = u;
    }
    int pilha[E + 1], topo = 0, ordem[E + 1], n = 0;
    pilha[topo++] = ini;
    while (topo > 0) {
        int u = pilha[topo - 1], v = 0;
        while (v < V && trecho[u][v] == 0) v++;
        if (v < V) {
            trecho[u][v]--;
            pilha[topo++] = v;
        } else {
            ordem[n++] = u;
            topo--;
        }
    }
    printf("Trajeto:");
    for (int i = n - 1; i >= 0; i--) printf(" %d", ordem[i]);
    printf("\n");
    return 0;
}
