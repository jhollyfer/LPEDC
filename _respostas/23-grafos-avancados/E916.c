// 0153 · Prim: a árvore que cresce
// Exercício E916 · ★★☆

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 8
#define INFINITO INT_MAX

const char *pontos[V] = {"Central", "Padaria", "Escola", "Igreja", "Farmácia", "Praça", "Posto", "Clínica"};
int fibra[V][V];
int pai[V];

// mostra v e, embaixo dele com mais recuo, quem se pendurou nele
void mostra(int v, int nivel) {
    if (pai[v] == -1) printf("%s\n", pontos[v]);
    else printf("%*s%s (%d)\n", 2 * nivel, "", pontos[v], fibra[pai[v]][v]);
    for (int w = 0; w < V; w++)
        if (pai[w] == v) mostra(w, nivel + 1);
}

int main(void) {
    int trechos[][3] = {{0, 1, 2}, {0, 2, 4}, {1, 2, 3}, {1, 3, 5}, {2, 4, 2}, {3, 5, 1},
                        {4, 5, 6}, {2, 6, 7}, {4, 7, 3}, {6, 7, 2}, {0, 6, 9}};
    for (int k = 0; k < 11; k++) {
        fibra[trechos[k][0]][trechos[k][1]] = trechos[k][2];
        fibra[trechos[k][1]][trechos[k][0]] = trechos[k][2];
    }

    int chave[V], total = 0;
    bool na_rede[V] = {false};
    for (int v = 0; v < V; v++) {
        chave[v] = INFINITO;
        pai[v] = -1;
    }
    chave[0] = 0;
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!na_rede[v] && chave[v] != INFINITO && (u == -1 || chave[v] < chave[u])) u = v;
        if (u == -1) break;
        na_rede[u] = true;
        total += chave[u];
        for (int v = 0; v < V; v++)
            if (fibra[u][v] && !na_rede[v] && fibra[u][v] < chave[v]) {
                chave[v] = fibra[u][v];
                pai[v] = u;
            }
    }
    mostra(0, 0);
    printf("Total: %d km\n", total);
    return 0;
}
