// 0183 · Hamiltoniano
// Exercício E1093 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define V 6

int via[V][V];

bool eh_ciclo_hamiltoniano(const int rota[], int n) {
    if (n != V) return false;
    bool visto[V] = {false};
    for (int i = 0; i < n; i++) {
        if (rota[i] < 0 || rota[i] >= V || visto[rota[i]]) return false;
        visto[rota[i]] = true;
    }
    for (int i = 0; i < n; i++)
        if (!via[rota[i]][rota[(i + 1) % n]]) return false; // inclui a volta
    return true;
}

int main(void) {
    int vias[][2] = {{0, 1}, {0, 2}, {0, 4}, {1, 2}, {1, 3}, {2, 3}, {3, 4}, {3, 5}, {4, 5}};
    for (int k = 0; k < 9; k++) via[vias[k][0]][vias[k][1]] = via[vias[k][1]][vias[k][0]] = 1;

    int r1[] = {0, 1, 2, 3, 5, 4};
    int r2[] = {0, 1, 2, 3, 4, 5};
    int r3[] = {0, 2, 1, 3, 5, 4};
    int r4[] = {0, 1, 3, 5, 4, 1};
    printf("Rota 1: %s\n", eh_ciclo_hamiltoniano(r1, 6) ? "válida" : "inválida");
    printf("Rota 2: %s\n", eh_ciclo_hamiltoniano(r2, 6) ? "válida" : "inválida");
    printf("Rota 3: %s\n", eh_ciclo_hamiltoniano(r3, 6) ? "válida" : "inválida");
    printf("Rota 4: %s\n", eh_ciclo_hamiltoniano(r4, 6) ? "válida" : "inválida");
    return 0;
}
