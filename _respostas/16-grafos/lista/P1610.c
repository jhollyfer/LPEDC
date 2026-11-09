// Lista · Módulo 16 · Grafos
// Exercício P1610 · ★☆☆ · Comunidades do rio: quantas lanchas faltam

#include <stdio.h>

#define V 9

int adj[V][V];
int comp[V];

void dfs(int u, int k) {
    comp[u] = k;
    for (int v = 0; v < V; v++)
        if (adj[u][v] && comp[v] == -1) dfs(v, k);
}

int main(void) {
    int linhas[][2] = {{0, 1}, {1, 2}, {0, 2}, {3, 4}, {5, 6}, {6, 7}, {5, 7}};
    for (int k = 0; k < 7; k++) adj[linhas[k][0]][linhas[k][1]] = adj[linhas[k][1]][linhas[k][0]] = 1;

    for (int v = 0; v < V; v++) comp[v] = -1;
    int k = 0;
    for (int v = 0; v < V; v++)
        if (comp[v] == -1) dfs(v, k++); // cada DFS nova é um componente novo

    for (int c = 0; c < k; c++) {
        printf("Componente %d:", c);
        for (int v = 0; v < V; v++)
            if (comp[v] == c) printf(" %d", v);
        printf("\n");
    }
    printf("Componentes: %d\n", k);
    printf("Linhas novas necessárias: %d\n", k - 1);
    return 0;
}
