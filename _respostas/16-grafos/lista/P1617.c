// Lista · Módulo 16 · Grafos
// Exercício P1617 · ★★☆ · Amigos de amigos: o quadrado do grafo

#include <stdio.h>

#define V 6

const char *nomes[V] = {"Aline", "Bento", "Caua", "Dora", "Edson", "Flora"};
int g[V][V];

void quadrado(int g[V][V], int q[V][V]) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) {
            q[i][j] = 0;
            if (i == j) continue; // ninguém é sugerido para si mesmo
            if (g[i][j]) q[i][j] = 1;
            for (int k = 0; k < V && !q[i][j]; k++)
                if (g[i][k] && g[k][j]) q[i][j] = 1; // i - k - j
        }
}

int conta(int m[V][V]) {
    int total = 0;
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++) total += m[i][j];
    return total;
}

int main(void) {
    int amizades[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {1, 5}};
    for (int k = 0; k < 5; k++) g[amizades[k][0]][amizades[k][1]] = g[amizades[k][1]][amizades[k][0]] = 1;

    int q[V][V];
    quadrado(g, q);
    printf("Arestas em G: %d | em G²: %d\n", conta(g), conta(q));
    printf("Sugestões:\n");
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            if (q[i][j] && !g[i][j]) printf("  %s-%s\n", nomes[i], nomes[j]);
    return 0;
}
