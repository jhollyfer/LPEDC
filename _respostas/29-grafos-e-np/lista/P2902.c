// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2902 · ★☆☆ · Fontes e sumidouros

#include <stdio.h>

#define V 8
#define E 9

const char *tarefas[V] = {"Projeto", "Demolição", "Elétrica", "Hidráulica", "Reboco", "Piso", "Pintura", "Limpeza"};
int antes[V][V];

int main(void) {
    int s[E][2] = {{0, 1}, {1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}, {4, 6}, {5, 7}, {6, 7}};
    for (int k = 0; k < E; k++) antes[s[k][0]][s[k][1]] = 1;
    int entra[V] = {0}, sai[V] = {0}, se = 0, ss = 0;
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++) sai[u] += antes[u][v], entra[v] += antes[u][v];
    for (int u = 0; u < V; u++) {
        printf("%s: entrada %d, saída %d\n", tarefas[u], entra[u], sai[u]);
        se += entra[u], ss += sai[u];
    }
    printf("Somas: entrada %d, saída %d\n", se, ss);
    printf("Fontes:");
    for (int u = 0; u < V; u++)
        if (entra[u] == 0) printf(" %s", tarefas[u]);
    printf("\nSumidouros:");
    for (int u = 0; u < V; u++)
        if (sai[u] == 0) printf(" %s", tarefas[u]);
    printf("\n");
    return 0;
}
