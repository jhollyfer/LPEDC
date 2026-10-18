// 0153 · Prim: a árvore que cresce
// Exercício E913 · ★☆☆

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INFINITO INT_MAX

int main(void) {
    const char *nomes[V] = {"Gerador", "Coco", "Pastel", "Açaí", "Milho"};
    int cabo[V][V] = {
        {0, 12, 20, 25, 0},
        {12, 0, 9, 0, 30},
        {20, 9, 0, 6, 15},
        {25, 0, 6, 0, 11},
        {0, 30, 15, 11, 0},
    };
    int chave[V], pai[V];
    bool na_rede[V] = {false};
    for (int v = 0; v < V; v++) {
        chave[v] = INFINITO;
        pai[v] = -1;
    }
    chave[0] = 0;

    int total = 0;
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!na_rede[v] && chave[v] != INFINITO && (u == -1 || chave[v] < chave[u])) u = v;
        if (u == -1) break;
        na_rede[u] = true;
        total += chave[u];
        if (pai[u] != -1) printf("%s - %s: %d m\n", nomes[pai[u]], nomes[u], chave[u]);
        for (int v = 0; v < V; v++)
            if (cabo[u][v] && !na_rede[v] && cabo[u][v] < chave[v]) {
                chave[v] = cabo[u][v];
                pai[v] = u;
            }
    }
    printf("Total: %d m\n", total);
    return 0;
}
