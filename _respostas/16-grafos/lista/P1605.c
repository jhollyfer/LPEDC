// Lista · Módulo 16 · Grafos
// Exercício P1605 · ★☆☆ · O complemento: quem ainda precisa ser apresentado

#include <stdio.h>

#define V 6

const char *nomes[V] = {"Raimundo", "Socorro", "Tiago", "Ubiratan", "Vania", "Wesley"};
int conhece[V][V] = {
    {0, 1, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0},
    {1, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 0},
};

void complemento(int g[V][V], int c[V][V]) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) c[i][j] = (i != j && !g[i][j]);
}

int arestas(int g[V][V]) {
    int total = 0;
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++) total += g[i][j];
    return total;
}

int main(void) {
    int c[V][V];
    complemento(conhece, c);
    for (int i = 0; i < V; i++) {
        printf("%-9s:", nomes[i]);
        for (int j = 0; j < V; j++)
            if (c[i][j]) printf(" %s", nomes[j]);
        printf("\n");
    }
    int e = arestas(conhece), ec = arestas(c);
    printf("conhece: %d | complemento: %d | total: %d = %d·%d/2\n", e, ec, e + ec, V, V - 1);
    return 0;
}
