// Lista · Módulo 16 · Grafos
// Exercício P1614 · ★★☆ · O anel na rede de água: ache e mostre o ciclo

#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *nomes[V] = {"Reservatorio", "Valvula", "Caixa", "Escola", "Posto", "Feira", "Praca"};
int adj[V][V];
bool visitado[V];
int pai[V];
bool achou;

void dfs(int u) {
    visitado[u] = true;
    for (int v = 0; v < V && !achou; v++) {
        if (!adj[u][v]) continue;
        if (!visitado[v]) {
            pai[v] = u;
            dfs(v);
        } else if (v != pai[u]) { // aresta de retorno: v é ancestral de u
            printf("Ciclo:");
            for (int x = u; x != v; x = pai[x]) printf(" %s ->", nomes[x]);
            printf(" %s -> %s\n", nomes[v], nomes[u]);
            achou = true;
        }
    }
}

void procura(void) {
    achou = false;
    for (int v = 0; v < V; v++) {
        visitado[v] = false;
        pai[v] = -1;
    }
    for (int v = 0; v < V && !achou; v++)
        if (!visitado[v]) dfs(v);
    if (!achou) printf("sem ciclo\n");
}

int main(void) {
    int canos[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}, {0, 5}, {5, 6}};
    for (int k = 0; k < 7; k++) adj[canos[k][0]][canos[k][1]] = adj[canos[k][1]][canos[k][0]] = 1;

    procura();
    adj[1][2] = adj[2][1] = 0; // tira o cano Valvula-Caixa
    printf("Sem Valvula-Caixa: ");
    procura();
    return 0;
}
