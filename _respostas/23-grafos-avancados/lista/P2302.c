// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2302 · ★☆☆ · O cano que fecha o circuito

#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *casas[V] = {"Poço", "Ana", "Beto", "Cida", "Davi", "Elza"};
int cano[V][V];
bool visto[V];
int pai[V];
int ini, fim; // o cano fim-ini fecha o circuito

// DFS que lembra o pai: vizinho já visto que não é o pai fecha um circuito
bool dfs(int u) {
    visto[u] = true;
    for (int v = 0; v < V; v++) {
        if (!cano[u][v]) continue;
        if (!visto[v]) {
            pai[v] = u;
            if (dfs(v)) return true;
        } else if (v != pai[u]) {
            ini = v;
            fim = u;
            return true;
        }
    }
    return false;
}

void analisa(const char *rotulo) {
    for (int u = 0; u < V; u++) {
        visto[u] = false;
        pai[u] = -1;
    }
    bool achou = false;
    for (int u = 0; u < V && !achou; u++)
        if (!visto[u]) achou = dfs(u);
    if (!achou) {
        printf("%s: sem circuito\n", rotulo);
        return;
    }
    printf("%s: o cano %s-%s fecha o circuito", rotulo, casas[fim], casas[ini]);
    int caminho[V], n = 0;
    for (int x = fim; x != ini; x = pai[x]) caminho[n++] = x;
    caminho[n++] = ini;
    for (int k = n - 1; k >= 0; k--) printf("%s%s", k == n - 1 ? " " : " - ", casas[caminho[k]]);
    printf(" - %s\n", casas[ini]);
}

void liga(int a, int b, int valor) {
    cano[a][b] = valor;
    cano[b][a] = valor;
}

int main(void) {
    int canos[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {1, 4}, {4, 5}};
    for (int k = 0; k < 6; k++) liga(canos[k][0], canos[k][1], 1);
    analisa("Rede atual");

    liga(1, 4, 0); // a vila tirou o cano Ana-Davi
    analisa("Rede nova");
    return 0;
}
