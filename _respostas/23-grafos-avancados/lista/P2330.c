// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2330 · ★★★ · Quantas ruas novas no centro histórico

#include <stdbool.h>
#include <stdio.h>

#define V 9

const char *largos[V] = {"Sé", "Carmo", "Rosário", "Mercado", "Teatro",
                         "Matriz", "Cais", "Estação", "Feira"};
int rua[V][V], inversa[V][V];
bool visto[V];
int ordem[V], n_ordem = 0;
int grupo[V];

void dfs1(int u) {
    visto[u] = true;
    for (int v = 0; v < V; v++)
        if (rua[u][v] && !visto[v]) dfs1(v);
    ordem[n_ordem++] = u;
}

void dfs2(int u, int g) {
    grupo[u] = g;
    for (int v = 0; v < V; v++)
        if (inversa[u][v] && grupo[v] == 0) dfs2(v, g);
}

int main(void) {
    int maos[][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 3}, {1, 5}, {6, 5}, {7, 8}, {8, 7}, {7, 0}};
    for (int k = 0; k < 11; k++) {
        rua[maos[k][0]][maos[k][1]] = 1;
        inversa[maos[k][1]][maos[k][0]] = 1;
    }
    for (int u = 0; u < V; u++)
        if (!visto[u]) dfs1(u);
    int g = 0;
    for (int i = V - 1; i >= 0; i--)
        if (grupo[ordem[i]] == 0) dfs2(ordem[i], ++g);

    // o grafo dos grupos: só as setas que ligam grupos diferentes
    bool entra[V + 1] = {false}, sai[V + 1] = {false};
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++)
            if (rua[a][b] && grupo[a] != grupo[b]) {
                sai[grupo[a]] = true;
                entra[grupo[b]] = true;
            }

    int fontes = 0, sumidouros = 0;
    for (int k = 1; k <= g; k++) {
        printf("Grupo %d:", k);
        for (int u = 0; u < V; u++)
            if (grupo[u] == k) printf(" %s", largos[u]);
        if (!entra[k]) {
            fontes++;
            printf(" (ninguém chega)");
        }
        if (!sai[k]) {
            sumidouros++;
            printf(" (não sai)");
        }
        printf("\n");
    }
    int novas = g == 1 ? 0 : (fontes > sumidouros ? fontes : sumidouros);
    printf("Fontes: %d, sumidouros: %d\n", fontes, sumidouros);
    printf("Ruas novas, no mínimo: %d\n", novas);
    return 0;
}
