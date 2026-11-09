// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2307 · ★☆☆ · As chaves do Prim

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INF INT_MAX

const char *lugares[V] = {"Usina", "Boa Vista", "Bom Jesus", "Santa Luzia", "São José"};
int km[V][V];

void mostra_chaves(const int chave[], const bool na_rede[]) {
    printf("  chave:");
    for (int v = 0; v < V; v++) {
        if (chave[v] == INF) printf("   -");
        else printf(" %3d", chave[v]);
        printf("%s", na_rede[v] ? "*" : " ");
    }
    printf("\n");
}

int main(void) {
    int linhas[][3] = {{0, 1, 6}, {0, 2, 3}, {1, 2, 4}, {1, 3, 2}, {2, 3, 7}, {2, 4, 8}, {3, 4, 5}, {0, 4, 9}};
    for (int k = 0; k < 8; k++) {
        km[linhas[k][0]][linhas[k][1]] = linhas[k][2];
        km[linhas[k][1]][linhas[k][0]] = linhas[k][2];
    }

    int chave[V], pai[V];
    bool na_rede[V];
    for (int v = 0; v < V; v++) {
        chave[v] = INF;
        pai[v] = -1;
        na_rede[v] = false;
    }
    chave[0] = 0;
    int total = 0;
    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!na_rede[v] && chave[v] != INF && (u == -1 || chave[v] < chave[u])) u = v;
        na_rede[u] = true;
        if (pai[u] == -1) printf("entra %s\n", lugares[u]);
        else {
            printf("entra %s: %s - %s, %d km\n", lugares[u], lugares[pai[u]], lugares[u], km[pai[u]][u]);
            total += km[pai[u]][u];
        }
        for (int v = 0; v < V; v++)
            if (km[u][v] && !na_rede[v] && km[u][v] < chave[v]) {
                chave[v] = km[u][v];
                pai[v] = u;
            }
        mostra_chaves(chave, na_rede);
    }
    printf("Total: %d km\n", total);
    return 0;
}
