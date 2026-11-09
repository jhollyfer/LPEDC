// 0187 · Reduções
// Exercício E1118 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *esquinas[V] = {"A", "B", "C", "D", "E", "F", "G"};
int rua[V][V];

bool cobre(const bool em[]) {
    for (int a = 0; a < V; a++)
        for (int b = a + 1; b < V; b++)
            if (rua[a][b] && !em[a] && !em[b]) return false;
    return true;
}

bool independente(const bool em[]) {
    for (int a = 0; a < V; a++)
        for (int b = a + 1; b < V; b++)
            if (rua[a][b] && em[a] && em[b]) return false;
    return true;
}

int main(void) {
    int ruas[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 5}, {2, 4}};
    for (int k = 0; k < 8; k++) rua[ruas[k][0]][ruas[k][1]] = rua[ruas[k][1]][ruas[k][0]] = 1;

    bool planos[2][V] = {
        {false, true, false, true, true, true, false}, // B, D, E, F
        {false, true, false, true, false, true, false}, // B, D, F
    };
    for (int p = 0; p < 2; p++) {
        bool resto[V];
        for (int v = 0; v < V; v++) resto[v] = !planos[p][v];
        printf("Plano %d: câmeras em", p + 1);
        for (int v = 0; v < V; v++)
            if (planos[p][v]) printf(" %s", esquinas[v]);
        printf("\n  cobre todas as ruas? %s\n", cobre(planos[p]) ? "sim" : "não");
        printf("  sem câmera:");
        for (int v = 0; v < V; v++)
            if (resto[v]) printf(" %s", esquinas[v]);
        printf("\n  independente? %s\n", independente(resto) ? "sim" : "não");
    }
    return 0;
}
