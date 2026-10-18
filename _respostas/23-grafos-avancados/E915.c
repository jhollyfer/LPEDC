// 0153 · Prim: a árvore que cresce
// Exercício E915 · ★★☆

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 6
#define INFINITO INT_MAX

const char *estacoes[V] = {"Rodoviária", "Praça", "Museu", "Orla", "Feira", "Estádio"};
int dist[V][V];

int prim(int origem) {
    int chave[V], total = 0;
    bool na_rede[V] = {false};
    for (int v = 0; v < V; v++) chave[v] = INFINITO;
    chave[origem] = 0;
    printf("%s:", estacoes[origem]);
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!na_rede[v] && chave[v] != INFINITO && (u == -1 || chave[v] < chave[u])) u = v;
        if (u == -1) break;
        na_rede[u] = true;
        total += chave[u];
        printf(" %s", estacoes[u]);
        for (int v = 0; v < V; v++)
            if (dist[u][v] && !na_rede[v] && dist[u][v] < chave[v]) chave[v] = dist[u][v];
    }
    printf(" | %d\n", total);
    return total;
}

int main(void) {
    int trechos[][3] = {{0, 1, 5}, {0, 4, 3}, {1, 2, 4}, {1, 4, 6}, {2, 3, 2},
                        {4, 3, 7}, {3, 5, 8}, {2, 5, 9}, {4, 5, 10}};
    for (int k = 0; k < 9; k++) {
        dist[trechos[k][0]][trechos[k][1]] = trechos[k][2];
        dist[trechos[k][1]][trechos[k][0]] = trechos[k][2];
    }
    for (int origem = 0; origem < V; origem++) prim(origem);
    return 0;
}
