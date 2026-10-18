// 0110 · BFS: busca em largura
// Exercício E658 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define V 8

int main(void) {
    int adj[V][V] = {0};
    int cabos[][2] = {{0, 1}, {1, 2}, {3, 4}, {5, 6}, {6, 7}, {5, 7}};
    for (int k = 0; k < 6; k++) {
        adj[cabos[k][0]][cabos[k][1]] = 1;
        adj[cabos[k][1]][cabos[k][0]] = 1;
    }

    bool visitado[V] = {false};
    int grupos = 0;
    for (int s = 0; s < V; s++) {
        if (visitado[s]) continue;
        grupos++; // s abre um grupo novo
        printf("Grupo %d:", grupos);
        int fila[V], inicio = 0, fim = 0;
        visitado[s] = true;
        fila[fim++] = s;
        while (inicio < fim) {
            int u = fila[inicio++];
            printf(" %c", 'A' + u);
            for (int v = 0; v < V; v++) {
                if (adj[u][v] && !visitado[v]) {
                    visitado[v] = true;
                    fila[fim++] = v;
                }
            }
        }
        printf("\n");
    }
    printf("Total de grupos: %d\n", grupos);
    return 0;
}
