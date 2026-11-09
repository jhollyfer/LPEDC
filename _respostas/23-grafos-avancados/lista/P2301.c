// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2301 · ★☆☆ · Grupos do condomínio

#include <stdio.h>

#define V 9

const char *nomes[V] = {"Ana", "Bia", "Caio", "Duda", "Edu", "Fabi", "Gil", "Hugo", "Iara"};
int amigo[V][V];
int grupo[V]; // 0 = ainda sem grupo

// DFS: põe no grupo g todo mundo que u alcança
void marca(int u, int g) {
    grupo[u] = g;
    for (int v = 0; v < V; v++)
        if (amigo[u][v] && grupo[v] == 0) marca(v, g);
}

int main(void) {
    int pares[][2] = {{0, 2}, {2, 6}, {1, 3}, {3, 7}, {4, 5}};
    for (int k = 0; k < 5; k++) {
        amigo[pares[k][0]][pares[k][1]] = 1;
        amigo[pares[k][1]][pares[k][0]] = 1;
    }

    int g = 0;
    for (int u = 0; u < V; u++)
        if (grupo[u] == 0) marca(u, ++g);

    for (int k = 1; k <= g; k++) {
        printf("Grupo %d:", k);
        for (int u = 0; u < V; u++)
            if (grupo[u] == k) printf(" %s", nomes[u]);
        printf("\n");
    }

    int consultas[][2] = {{0, 6}, {1, 4}, {7, 1}, {8, 0}};
    for (int k = 0; k < 4; k++) {
        int a = consultas[k][0], b = consultas[k][1];
        printf("%s e %s: %s\n", nomes[a], nomes[b], grupo[a] == grupo[b] ? "mesmo grupo" : "grupos diferentes");
    }
    return 0;
}
