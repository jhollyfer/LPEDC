// 0151 · Ordenação topológica
// Exercício E901 · ★☆☆

#include <stdio.h>

#define V 8

int main(void) {
    const char *passos[V] = {"bater os ovos", "desenformar", "despejar na forma", "misturar os secos",
                             "juntar tudo", "preaquecer o forno", "untar a forma", "assar"};
    int antes[V][V] = {0};
    int regras[][2] = {{0, 4}, {3, 4}, {4, 2}, {6, 2}, {2, 7}, {5, 7}, {7, 1}};
    for (int k = 0; k < 7; k++) antes[regras[k][0]][regras[k][1]] = 1;

    int grau[V] = {0};
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) grau[b] += antes[a][b];

    int fila[V], inicio = 0, fim = 0;
    for (int v = 0; v < V; v++)
        if (grau[v] == 0) fila[fim++] = v;

    int feitos = 0;
    while (inicio < fim) {
        int u = fila[inicio++];
        printf("%d. %s\n", ++feitos, passos[u]);
        for (int v = 0; v < V; v++)
            if (antes[u][v] && --grau[v] == 0) fila[fim++] = v;
    }
    if (feitos < V) printf("Receita com ciclo!\n");
    return 0;
}
