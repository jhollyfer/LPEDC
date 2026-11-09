// Lista · Módulo 16 · Grafos
// Exercício P1609 · ★☆☆ · DFS com relógio: os tempos d e f

#include <stdio.h>

#define V 6

enum { BRANCO, CINZA, PRETO };

const char *nomes[V] = {"Portao", "Lago", "Mirante", "Viveiro", "Cascata", "Quiosque"};
int adj[V][V];
int cor[V], d[V], f[V];
int relogio = 0;
int ordem_fim[V], terminados = 0;

void dfs_visita(int u) {
    d[u] = ++relogio; // descoberto: fica cinza
    cor[u] = CINZA;
    for (int v = 0; v < V; v++)
        if (adj[u][v] && cor[v] == BRANCO) dfs_visita(v);
    cor[u] = PRETO; // todos os vizinhos explorados
    f[u] = ++relogio;
    ordem_fim[terminados++] = u;
}

int main(void) {
    int trilhas[][2] = {{0, 1}, {0, 3}, {1, 2}, {2, 0}, {3, 2}, {3, 4}, {5, 4}, {5, 3}};
    for (int k = 0; k < 8; k++) adj[trilhas[k][0]][trilhas[k][1]] = 1;

    for (int u = 0; u < V; u++) cor[u] = BRANCO;
    for (int u = 0; u < V; u++)
        if (cor[u] == BRANCO) dfs_visita(u);

    for (int u = 0; u < V; u++) printf("%-9s %2d/%2d\n", nomes[u], d[u], f[u]);
    printf("Terminam:");
    for (int k = 0; k < V; k++) printf(" %s", nomes[ordem_fim[k]]);
    printf("\n");
    return 0;
}
