// 0182 · Caminhos e ciclos
// Exercício E1091 · ★★★

#include <stdio.h>

#define V 6
#define MAX_PILHA 40

const char letra[V] = {'G', 'P', 'F', 'E', 'I', 'S'};
int rua[V][V];

int main(void) {
    int ruas[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 5}, {2, 4}, {2, 5}, {3, 4}};
    int e = 8;
    for (int k = 0; k < e; k++) {
        rua[ruas[k][0]][ruas[k][1]] = 1;
        rua[ruas[k][1]][ruas[k][0]] = 1;
    }

    int pilha[MAX_PILHA], topo = 0, circuito[MAX_PILHA], n = 0;
    pilha[topo++] = 0;
    while (topo > 0) {
        int u = pilha[topo - 1], v = 0;
        while (v < V && rua[u][v] == 0) v++;
        if (v < V) {
            rua[u][v] = rua[v][u] = 0; // apaga a rua nos dois sentidos
            pilha[topo++] = v;
        } else {
            circuito[n++] = u;
            topo--;
        }
    }
    printf("Circuito:");
    for (int i = n - 1; i >= 0; i--) printf(" %c", letra[circuito[i]]);
    printf("\nRuas percorridas: %d de %d\n", n - 1, e);
    return 0;
}
