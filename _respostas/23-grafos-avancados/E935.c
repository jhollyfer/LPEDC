// 0156 · Juntando tudo: o assistente do calouro
// Exercício E935 · ★★★

#include <stdio.h>

#define V 7

const char *disc[V] = {"Lógica", "Cálculo", "C", "Estruturas", "Arquivos", "Grafos", "Projeto"};
int antes[V][V];

int main(void) {
    int regras[][2] = {{0, 2}, {2, 3}, {2, 4}, {1, 5}, {3, 5}, {4, 6}, {5, 6}};
    for (int k = 0; k < 7; k++) antes[regras[k][0]][regras[k][1]] = 1;

    int grau[V] = {0};
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) grau[b] += antes[a][b];

    int fila[V], inicio = 0, fim = 0;
    for (int v = 0; v < V; v++)
        if (grau[v] == 0) fila[fim++] = v;

    int semestre = 0;
    while (inicio < fim) {
        int fim_semestre = fim; // o semestre é quem já está liberado agora
        printf("%dº semestre (%d na fila):", ++semestre, fim_semestre - inicio);
        while (inicio < fim_semestre) { // só quem estava liberado no começo do semestre
            int u = fila[inicio++];
            printf(" %s", disc[u]);
            for (int v = 0; v < V; v++)
                if (antes[u][v] && --grau[v] == 0) fila[fim++] = v; // fica para depois
        }
        printf("\n");
    }
    return 0;
}
