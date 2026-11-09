// 0184 · Pontes e articulações
// Exercício E1099 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *cidades[V] = {"Manaus", "Iranduba", "Manacapuru", "Novo Airão", "Rio Preto da Eva", "Itacoatiara"};
int estrada[V][V];
bool visto[V];

void dfs(int u, int fora) {
    visto[u] = true;
    for (int v = 0; v < V; v++)
        if (estrada[u][v] && !visto[v] && v != fora) dfs(v, fora);
}

int componentes(int fora) {
    for (int u = 0; u < V; u++) visto[u] = false;
    int c = 0;
    for (int u = 0; u < V; u++)
        if (u != fora && !visto[u]) c++, dfs(u, fora);
    return c;
}

int main(void) {
    int rodovias[][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {0, 4}, {4, 5}};
    for (int k = 0; k < 6; k++) estrada[rodovias[k][0]][rodovias[k][1]] = estrada[rodovias[k][1]][rodovias[k][0]] = 1;

    int base = componentes(-1);
    printf("Pontes:\n");
    for (int k = 0; k < 6; k++) {
        int a = rodovias[k][0], b = rodovias[k][1];
        estrada[a][b] = estrada[b][a] = 0;
        if (componentes(-1) > base) printf("  %s - %s\n", cidades[a], cidades[b]);
        estrada[a][b] = estrada[b][a] = 1;
    }
    printf("Articulações:\n");
    for (int u = 0; u < V; u++)
        if (componentes(u) > base) printf("  %s\n", cidades[u]);
    return 0;
}
