// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2323 · ★★★ · Kosaraju de mão trocada

#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *perfis[V] = {"@ana", "@beto", "@caio", "@dani", "@enzo", "@fe", "@gabi"};
int segue[V][V];   // segue[a][b] = 1: a segue b
int inversa[V][V];
bool visto[V];
int ordem[V], n_ordem = 0;
int grupo[V];

void dfs1(int u) {
    visto[u] = true;
    for (int v = 0; v < V; v++)
        if (segue[u][v] && !visto[v]) dfs1(v);
    ordem[n_ordem++] = u;
}

void dfs2(int u, int g) {
    grupo[u] = g;
    for (int v = 0; v < V; v++)
        if (inversa[u][v] && grupo[v] == 0) dfs2(v, g); // o conserto: anda nas setas invertidas
}

int main(void) {
    int pares[][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 3}, {4, 5}, {5, 6}, {6, 5}, {1, 6}};
    for (int k = 0; k < 10; k++) {
        segue[pares[k][0]][pares[k][1]] = 1;
        inversa[pares[k][1]][pares[k][0]] = 1;
    }
    for (int u = 0; u < V; u++)
        if (!visto[u]) dfs1(u);

    int g = 0;
    for (int i = V - 1; i >= 0; i--)
        if (grupo[ordem[i]] == 0) dfs2(ordem[i], ++g);

    for (int k = 1; k <= g; k++) {
        printf("Bolha %d:", k);
        for (int u = 0; u < V; u++)
            if (grupo[u] == k) printf(" %s", perfis[u]);
        printf("\n");
    }
    return 0;
}
