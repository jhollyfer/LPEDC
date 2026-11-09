// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2901 · ★☆☆ · Graus do metrô

#include <stdio.h>

#define V 7
#define E 9

const char *estacoes[V] = {"Sé", "Luz", "Brás", "Arena", "Parque", "Vila", "Porto"};
int trilho[V][V];

int main(void) {
    int t[E][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}, {3, 5}, {5, 6}};
    for (int k = 0; k < E; k++) trilho[t[k][0]][t[k][1]] = trilho[t[k][1]][t[k][0]] = 1;
    int soma = 0, impares = 0, maior = 0, grau[V];
    for (int u = 0; u < V; u++) {
        grau[u] = 0;
        for (int v = 0; v < V; v++) grau[u] += trilho[u][v];
        printf("%s: %d\n", estacoes[u], grau[u]);
        soma += grau[u];
        if (grau[u] % 2) impares++;
        if (grau[u] > grau[maior]) maior = u;
    }
    printf("Maior grau: %s (%d)\n", estacoes[maior], grau[maior]);
    printf("Soma dos graus: %d = 2 x %d\n", soma, E);
    printf("Estações de grau ímpar: %d\n", impares);
    return 0;
}
