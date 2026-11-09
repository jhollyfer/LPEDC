// Lista · Módulo 16 · Grafos
// Exercício P1611 · ★★☆ · Menos conexões até Porto Alegre

#include <stdio.h>

#define V 10

const char *nomes[V] = {"Manaus", "Belem", "Brasilia", "Fortaleza", "Recife",
                        "Rio", "Sao Paulo", "Curitiba", "Porto Alegre", "Oiapoque"};
int adj[V][V];

void bfs(int s, int d[], int pi[]) {
    int fila[V], ini = 0, fim = 0;
    for (int v = 0; v < V; v++) d[v] = pi[v] = -1;
    d[s] = 0;
    fila[fim++] = s;
    while (ini < fim) {
        int u = fila[ini++];
        for (int v = 0; v < V; v++)
            if (adj[u][v] && d[v] == -1) {
                d[v] = d[u] + 1;
                pi[v] = u;
                fila[fim++] = v;
            }
    }
}

int caminho(const int pi[], int s, int t, int rota[]) {
    if (t != s && pi[t] == -1) return -1; // t nunca foi descoberto
    int n = 0;
    for (int v = t; v != -1; v = pi[v]) rota[n++] = v; // t, pi[t], ..., s
    for (int i = 0, j = n - 1; i < j; i++, j--) {      // inverte: s, ..., t
        int tmp = rota[i];
        rota[i] = rota[j];
        rota[j] = tmp;
    }
    return n - 1;
}

int main(void) {
    int trechos[][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 4}, {2, 6}, {3, 4},
                        {4, 5}, {5, 6}, {6, 7}, {7, 8}, {5, 8}};
    for (int k = 0; k < 11; k++) adj[trechos[k][0]][trechos[k][1]] = adj[trechos[k][1]][trechos[k][0]] = 1;

    int d[V], pi[V], rota[V];
    bfs(0, d, pi);
    int destinos[] = {8, 3, 9};
    for (int k = 0; k < 3; k++) {
        int t = destinos[k];
        int voos = caminho(pi, 0, t, rota);
        printf("%s: ", nomes[t]);
        if (voos == -1) {
            printf("sem rota\n");
            continue;
        }
        for (int i = 0; i <= voos; i++) printf("%s%s", i ? " -> " : "", nomes[rota[i]]);
        printf(" (%d voos, d = %d)\n", voos, d[t]);
    }
    return 0;
}
