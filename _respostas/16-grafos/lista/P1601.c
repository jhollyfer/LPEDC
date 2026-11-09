// Lista · Módulo 16 · Grafos
// Exercício P1601 · ★☆☆ · Grau das paradas e número de linhas

#include <stdio.h>

#define V 6

const char *nomes[V] = {"Centro", "Adrianopolis", "Cidade Nova", "Ponta Negra", "Compensa", "Aleixo"};
int adj[V][V] = {
    {0, 1, 0, 0, 1, 1},
    {1, 0, 1, 0, 0, 1},
    {0, 1, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 0},
    {1, 0, 0, 1, 0, 0},
    {1, 1, 1, 0, 0, 0},
};

int main(void) {
    int grau[V], soma = 0, maior = 0;

    for (int i = 0; i < V; i++) {
        grau[i] = 0;
        for (int j = 0; j < V; j++) grau[i] += adj[i][j]; // soma da linha i
        printf("%-13s grau %d\n", nomes[i], grau[i]);
        soma += grau[i];
        if (grau[i] > grau[maior]) maior = i; // estritamente maior: empate fica com o primeiro
    }
    printf("Soma dos graus: %d\n", soma);
    printf("Linhas (arestas): %d\n", soma / 2); // cada aresta conta duas vezes
    printf("Maior grau: %s (%d)\n", nomes[maior], grau[maior]);
    printf("Ponta de linha:");
    for (int i = 0; i < V; i++)
        if (grau[i] == 1) printf(" %s", nomes[i]);
    printf("\n");
    return 0;
}
