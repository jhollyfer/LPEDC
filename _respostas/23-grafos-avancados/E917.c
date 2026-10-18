// 0153 · Prim: a árvore que cresce
// Exercício E917 · ★★★

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define N 4      // casas
#define V (N + 1) // + o vértice imaginário "Água" (índice 0)
#define INFINITO INT_MAX

int main(void) {
    const char *nomes[V] = {"Água", "Ana", "Beto", "Cida", "Davi"};
    int poco[N] = {8, 5, 9, 7}; // custo de cavar um poço em cada casa (R$ mil)
    int custo[V][V] = {0};
    int canos[][3] = {{1, 2, 2}, {2, 3, 3}, {3, 4, 9}, {1, 4, 10}, {1, 3, 10}};
    for (int k = 0; k < 5; k++) {
        custo[canos[k][0]][canos[k][1]] = canos[k][2];
        custo[canos[k][1]][canos[k][0]] = canos[k][2];
    }
    for (int c = 1; c <= N; c++) { // cavar poço = ligar a casa na "Água"
        custo[0][c] = poco[c - 1];
        custo[c][0] = poco[c - 1];
    }

    int chave[V], pai[V], total = 0, pocos = 0;
    bool pronto[V] = {false};
    for (int v = 0; v < V; v++) {
        chave[v] = INFINITO;
        pai[v] = -1;
    }
    chave[0] = 0;
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!pronto[v] && chave[v] != INFINITO && (u == -1 || chave[v] < chave[u])) u = v;
        if (u == -1) break;
        pronto[u] = true;
        total += chave[u];
        if (pai[u] == 0) {
            printf("%s: cava poço (R$ %d mil)\n", nomes[u], chave[u]);
            pocos++;
        } else if (pai[u] > 0) {
            printf("%s: cano de %s (R$ %d mil)\n", nomes[u], nomes[pai[u]], chave[u]);
        }
        for (int v = 0; v < V; v++)
            if (custo[u][v] && !pronto[v] && custo[u][v] < chave[v]) {
                chave[v] = custo[u][v];
                pai[v] = u;
            }
    }
    printf("Total: R$ %d mil (%d poços)\n", total, pocos);
    return 0;
}
