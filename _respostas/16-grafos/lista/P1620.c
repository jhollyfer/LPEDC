// Lista · Módulo 16 · Grafos
// Exercício P1620 · ★★☆ · A celebridade da festa em O(V)

#include <stdio.h>

#define V 6

const char *nomes[V] = {"Ana", "Rubem", "Clara", "Davi", "Elis", "Fausto"};
int festa1[V][V] = {
    {0, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 1, 0},
    {0, 1, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
};
int festa2[V][V] = {
    {0, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
};
int consultas;

int conhece(int c[V][V], int i, int j) {
    consultas++;
    return c[i][j];
}

int celebridade(int c[V][V]) {
    int cand = 0;
    for (int i = 1; i < V; i++)
        if (conhece(c, cand, i)) cand = i; // quem conhece alguém não é celebridade
    for (int i = 0; i < V; i++) {
        if (i == cand) continue;
        if (conhece(c, cand, i) || !conhece(c, i, cand)) return -1; // confere o candidato
    }
    return cand;
}

int main(void) {
    int (*festas[])[V] = {festa1, festa2};
    for (int k = 0; k < 2; k++) {
        consultas = 0;
        int cel = celebridade(festas[k]);
        printf("Festa %d: %s (%d consultas de %d)\n", k + 1,
               cel == -1 ? "sem celebridade" : nomes[cel], consultas, V * V);
    }
    return 0;
}
