// 0188 · Aproximação
// Exercício E1128 · ★★★

#include <stdbool.h>
#include <stdio.h>

#define V 7
#define E 8

const char nome[V] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
const int rua[E][2] = {{1, 5}, {2, 4}, {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};

int main(void) {
    bool camera[V] = {false};
    printf("Ruas escolhidas:");
    for (int k = 0; k < E; k++) {
        int a = rua[k][0], b = rua[k][1];
        if (camera[a] || camera[b]) continue; // uma ponta basta para a rua estar vigiada
        printf(" %c-%c", nome[a], nome[b]);
        camera[a] = camera[b] = true;
    }
    int total = 0;
    printf("\nCâmeras em:");
    for (int v = 0; v < V; v++)
        if (camera[v]) printf(" %c", nome[v]), total++;
    printf(" (%d)\n", total);
    return 0;
}
