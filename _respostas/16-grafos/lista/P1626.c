// Lista · Módulo 16 · Grafos
// Exercício P1626 · ★★★ · O teorema dos parênteses no aeroporto

#include <stdio.h>

#define V 8

const char *nomes[V] = {"A", "B", "C", "D", "E", "F", "G", "H"};
// A check-in, B raio-x, C embarque, D free shop, E portão 1,
// F portão 2, G desembarque, H esteira
int adj[V][V];
int d[V], f[V], pi[V], relogio;

void dfs(int u) {
    d[u] = ++relogio;
    printf("%s(%s", relogio > 1 ? " " : "", nomes[u]);
    for (int v = 0; v < V; v++)
        if (adj[u][v] && d[v] == 0) { // d == 0: ainda branco
            pi[v] = u;
            dfs(v);
        }
    f[u] = ++relogio;
    printf(" %s)", nomes[u]);
}

int descende_pi(int v, int u) { // u aparece subindo de v por pi[]?
    for (int x = pi[v]; x != -1; x = pi[x])
        if (x == u) return 1;
    return 0;
}

int main(void) {
    int corredores[][2] = {{0, 1}, {1, 2}, {2, 3}, {2, 4}, {3, 4}, {4, 1}, {6, 7}, {7, 0}, {5, 4}};
    for (int k = 0; k < 9; k++) adj[corredores[k][0]][corredores[k][1]] = 1;

    for (int v = 0; v < V; v++) pi[v] = -1;
    for (int u = 0; u < V; u++)
        if (d[u] == 0) dfs(u);
    printf("\n");
    for (int u = 0; u < V; u++) printf("%s %2d/%2d\n", nomes[u], d[u], f[u]);

    int aninhados = 0, disjuntos = 0, cruzados = 0;
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++) {
            if ((d[i] < d[j] && f[j] < f[i]) || (d[j] < d[i] && f[i] < f[j])) aninhados++;
            else if (f[i] < d[j] || f[j] < d[i]) disjuntos++;
            else cruzados++;
        }
    printf("Pares: %d aninhados, %d disjuntos, %d cruzados\n", aninhados, disjuntos, cruzados);

    int b = 1;
    printf("Descendentes de B (intervalos):");
    for (int v = 0; v < V; v++)
        if (d[b] < d[v] && f[v] < f[b]) printf(" %s", nomes[v]);
    printf("\nDescendentes de B (pi):        ");
    for (int v = 0; v < V; v++)
        if (descende_pi(v, b)) printf(" %s", nomes[v]);
    printf("\n");
    return 0;
}
