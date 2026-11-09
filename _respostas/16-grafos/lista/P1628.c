// Lista · Módulo 16 · Grafos
// Exercício P1628 · ★★★ · A rede de fibra do campus é uma árvore?

#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *nomes[V] = {"Reitoria", "Biblioteca", "ICE", "FT", "Restaurante", "Hospital"};
int adj[V][V], d[V], pai[V], relogio, retorno;

void dfs(int u) {
    d[u] = ++relogio;
    for (int v = 0; v < V; v++) {
        if (!adj[u][v]) continue;
        if (d[v] == 0) {
            pai[v] = u;
            dfs(v);
        } else if (v != pai[u] && d[v] < d[u]) { // retorno, visto pelo lado de baixo
            printf("  ciclo fechado por %s-%s\n", nomes[u], nomes[v]);
            retorno++;
        }
    }
}

void diagnostico(const char *titulo, int cabos[][2], int e) {
    for (int i = 0; i < V; i++) {
        d[i] = 0;
        pai[i] = -1;
        for (int j = 0; j < V; j++) adj[i][j] = 0;
    }
    for (int k = 0; k < e; k++) adj[cabos[k][0]][cabos[k][1]] = adj[cabos[k][1]][cabos[k][0]] = 1;
    relogio = retorno = 0;

    printf("Rede %s:\n", titulo);
    int comp = 0;
    for (int v = 0; v < V; v++)
        if (d[v] == 0) {
            comp++;
            dfs(v);
        }
    printf("  V = %d, E = %d, componentes = %d\n", V, e, comp);
    if (comp == 1 && retorno == 0) {
        printf("  é árvore\n");
        return;
    }
    printf("  não é árvore: sobram %d cabo(s) (E - (V - comp) = %d), faltam %d\n",
           retorno, e - (V - comp), comp - 1);
}

int main(void) {
    int a[][2] = {{0, 1}, {1, 2}, {1, 3}, {3, 4}, {3, 5}};
    int b[][2] = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}};
    int c[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}, {1, 4}};

    diagnostico("A", a, 5);
    diagnostico("B", b, 5);
    diagnostico("C", c, 7);
    return 0;
}
