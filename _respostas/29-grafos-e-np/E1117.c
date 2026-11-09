// 0187 · Reduções
// Exercício E1117 · ★☆☆

#include <stdio.h>

#define V 5

const char *times[V] = {"Azul", "Verde", "Rubro", "Preto", "Branco"};
int jogou[V][V];
int falta[V][V];

void complemento(int g[V][V], int c[V][V]) {
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) c[a][b] = a != b && !g[a][b];
}

int main(void) {
    int jogos[][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {0, 4}};
    for (int k = 0; k < 6; k++) jogou[jogos[k][0]][jogos[k][1]] = jogou[jogos[k][1]][jogos[k][0]] = 1;

    complemento(jogou, falta);
    int arestas = 0;
    printf("Jogos que faltam:\n");
    for (int a = 0; a < V; a++)
        for (int b = a + 1; b < V; b++)
            if (falta[a][b]) printf("  %s x %s\n", times[a], times[b]), arestas++;
    printf("%d jogos feitos + %d faltando = %d\n", 6, arestas, V * (V - 1) / 2);
    return 0;
}
