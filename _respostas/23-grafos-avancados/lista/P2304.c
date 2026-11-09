// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2304 · ★☆☆ · O manual do guarda-roupa

#include <stdio.h>

#define V 7

const char *passos[V] = {"separar", "base", "laterais", "prateleiras", "portas", "puxadores", "fixar"};
int antes[V][V];

void kahn(const char *rotulo) {
    int grau[V] = {0}, fila[V], ini = 0, fimf = 0;
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) grau[b] += antes[a][b];
    for (int u = 0; u < V; u++)
        if (grau[u] == 0) fila[fimf++] = u;

    printf("%s:", rotulo);
    while (ini < fimf) {
        int u = fila[ini++];
        printf(" %s", passos[u]);
        for (int v = 0; v < V; v++)
            if (antes[u][v] && --grau[v] == 0) fila[fimf++] = v;
    }
    printf("\n");
    if (fimf < V) { // sobrou gente com grau > 0: estão presos num ciclo ou depois dele
        printf("  travados:");
        for (int u = 0; u < V; u++)
            if (grau[u] > 0) printf(" %s", passos[u]);
        printf("\n");
    }
}

int main(void) {
    int regras[][2] = {{0, 1}, {1, 2}, {2, 3}, {2, 4}, {4, 5}, {3, 6}, {4, 6}};
    for (int k = 0; k < 7; k++) antes[regras[k][0]][regras[k][1]] = 1;
    kahn("Manual certo");

    antes[5][2] = 1; // erro de impressão: puxadores antes das laterais
    kahn("Manual com erro");
    return 0;
}
