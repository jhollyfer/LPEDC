// Lista · Módulo 16 · Grafos
// Exercício P1604 · ★☆☆ · O grupo de estudos é completo?

#include <stdbool.h>
#include <stdio.h>

#define V 5

const char *nomes[V] = {"Iara", "Joao", "Kaue", "Luana", "Moacir"};
int m[V][V] = {
    {0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 0, 1},
    {0, 1, 0, 0, 1},
    {1, 0, 1, 1, 0},
};

int arestas(int m[V][V]) {
    int total = 0;
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++) total += m[i][j]; // metade de cima
    return total;
}

bool completo(int m[V][V]) {
    return arestas(m) == V * (V - 1) / 2;
}

int main(void) {
    printf("Arestas: %d de %d\n", arestas(m), V * (V - 1) / 2);
    printf("completo: %s\n", completo(m) ? "sim" : "não");
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            if (!m[i][j]) {
                printf("Falta: %s-%s\n", nomes[i], nomes[j]);
                m[i][j] = m[j][i] = 1; // a sessão que faltava
            }
    printf("Depois das sessões: %d arestas\n", arestas(m));
    printf("completo: %s\n", completo(m) ? "sim" : "não");
    return 0;
}
