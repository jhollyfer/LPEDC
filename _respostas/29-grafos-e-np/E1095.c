// 0183 · Hamiltoniano
// Exercício E1095 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define MAXV 6

int n;
int adj[MAXV][MAXV];
int rota[MAXV];
bool usado[MAXV];

int conta(int pos) {
    if (pos == n) return adj[rota[n - 1]][rota[0]];
    int total = 0;
    for (int v = 1; v < n; v++) {
        if (!adj[rota[pos - 1]][v] || usado[v]) continue;
        rota[pos] = v;
        usado[v] = true;
        total += conta(pos + 1); // não para no primeiro: soma todos
        usado[v] = false;
    }
    return total;
}

int ciclos(void) {
    for (int v = 0; v < n; v++) usado[v] = false;
    rota[0] = 0;
    usado[0] = true;
    return conta(1);
}

int main(void) {
    n = 6;
    int vias[][2] = {{0, 1}, {0, 2}, {0, 4}, {1, 2}, {1, 3}, {2, 3}, {3, 4}, {3, 5}, {4, 5}};
    for (int k = 0; k < 9; k++) adj[vias[k][0]][vias[k][1]] = adj[vias[k][1]][vias[k][0]] = 1;
    int c = ciclos();
    printf("Agências: %d rotas, %d ciclos distintos\n", c, c / 2);

    n = 5;
    for (int a = 0; a < n; a++)
        for (int b = 0; b < n; b++) adj[a][b] = a != b;
    c = ciclos();
    printf("Completo com 5: %d rotas, %d ciclos distintos\n", c, c / 2);
    return 0;
}
