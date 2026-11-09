// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2305 · ★☆☆ · Os relógios da DFS

#include <stdio.h>

#define V 6

const char *etapas[V] = {"lint", "testes", "build", "banco", "deploy", "aviso"};
int antes[V][V];
int visto[V];
int ordem[V], topo = V; // a ordem é preenchida de trás para a frente
int relogio = 0;
int d[V], f[V];

void dfs(int u) {
    visto[u] = 1;
    d[u] = ++relogio; // descobriu
    for (int v = 0; v < V; v++)
        if (antes[u][v] && !visto[v]) dfs(v);
    f[u] = ++relogio; // terminou
    ordem[--topo] = u;
}

int main(void) {
    int regras[][2] = {{0, 1}, {1, 2}, {2, 4}, {3, 4}, {4, 5}};
    for (int k = 0; k < 5; k++) antes[regras[k][0]][regras[k][1]] = 1;

    for (int u = 0; u < V; u++)
        if (!visto[u]) dfs(u);

    for (int u = 0; u < V; u++) printf("%-9s d = %2d  f = %2d\n", etapas[u], d[u], f[u]);
    printf("Ordem:");
    for (int i = 0; i < V; i++) printf(" %s(%d)", etapas[ordem[i]], f[ordem[i]]);
    printf("\n");
    return 0;
}
