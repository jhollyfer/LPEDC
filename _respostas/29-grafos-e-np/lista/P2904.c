// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2904 · ★☆☆ · Diagnóstico de Euler por lista de arestas

#include <stdbool.h>
#include <stdio.h>

#define MAXV 8

int m[MAXV][MAXV];
bool visto[MAXV];

void dfs(int u, int nv) {
    visto[u] = true;
    for (int v = 0; v < nv; v++)
        if (m[u][v] && !visto[v]) dfs(v, nv);
}

void diagnostico(int nv, int ne, int a[][2]) {
    int grau[MAXV] = {0};
    for (int u = 0; u < nv; u++)
        for (int v = 0; v < nv; v++) m[u][v] = 0;
    for (int k = 0; k < ne; k++) {
        grau[a[k][0]]++, grau[a[k][1]]++;
        m[a[k][0]][a[k][1]] = m[a[k][1]][a[k][0]] = 1;
    }
    for (int u = 0; u < nv; u++) visto[u] = false;
    int ini = 0;
    while (grau[ini] == 0) ini++;
    dfs(ini, nv);
    for (int u = 0; u < nv; u++)
        if (grau[u] > 0 && !visto[u]) {
            printf("nenhum (desconexo)\n");
            return;
        }
    int imp[MAXV], ni = 0;
    for (int u = 0; u < nv; u++)
        if (grau[u] % 2) imp[ni++] = u;
    if (ni == 0) printf("circuito\n");
    else if (ni == 2) printf("trajeto de %d a %d\n", imp[0], imp[1]);
    else printf("nenhum (%d esquinas ímpares)\n", ni);
}

int main(void) {
    int m1[][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 2}};
    int m2[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}, {1, 3}, {1, 4}, {4, 3}};
    int m3[][2] = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 3}};
    printf("Mapa 1: ");
    diagnostico(5, 6, m1);
    printf("Mapa 2: ");
    diagnostico(5, 8, m2);
    printf("Mapa 3: ");
    diagnostico(6, 6, m3);
    return 0;
}
