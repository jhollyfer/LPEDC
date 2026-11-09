// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2313 · ★★☆ · A trilha que vale mais pontos

#include <limits.h>
#include <stdio.h>

#define V 6

const char *fases[V] = {"Início", "Floresta", "Caverna", "Rio", "Castelo", "Chefão"};
int pontos[V][V]; // 0 = não há passagem
int tem[V][V];

int main(void) {
    int passagens[][3] = {{0, 1, 5}, {0, 2, 3}, {1, 3, 6}, {2, 3, 9}, {1, 4, 2}, {3, 4, 4}, {3, 5, 7}, {4, 5, 8}};
    for (int k = 0; k < 8; k++) {
        tem[passagens[k][0]][passagens[k][1]] = 1;
        pontos[passagens[k][0]][passagens[k][1]] = passagens[k][2];
    }

    // ordem topológica pelo Kahn
    int grau[V] = {0}, ordem[V], ini = 0, fim = 0;
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) grau[b] += tem[a][b];
    for (int u = 0; u < V; u++)
        if (grau[u] == 0) ordem[fim++] = u;
    while (ini < fim) {
        int u = ordem[ini++];
        for (int v = 0; v < V; v++)
            if (tem[u][v] && --grau[v] == 0) ordem[fim++] = v;
    }
    printf("Ordem:");
    for (int i = 0; i < V; i++) printf(" %s", fases[ordem[i]]);
    printf("\n");

    // relaxa "ao contrário": fica com o MAIOR total
    int melhor[V], pai[V];
    for (int v = 0; v < V; v++) {
        melhor[v] = INT_MIN;
        pai[v] = -1;
    }
    melhor[0] = 0;
    for (int i = 0; i < V; i++) {
        int u = ordem[i];
        if (melhor[u] == INT_MIN) continue;
        for (int v = 0; v < V; v++)
            if (tem[u][v] && melhor[u] + pontos[u][v] > melhor[v]) {
                melhor[v] = melhor[u] + pontos[u][v];
                pai[v] = u;
            }
    }
    for (int v = 0; v < V; v++) printf("%s: %d pontos\n", fases[v], melhor[v]);

    int caminho[V], n = 0;
    for (int x = V - 1; x != -1; x = pai[x]) caminho[n++] = x;
    printf("Melhor trilha:");
    for (int k = n - 1; k >= 0; k--) printf(" %s%s", fases[caminho[k]], k > 0 ? " ->" : "");
    printf("\n");
    return 0;
}
