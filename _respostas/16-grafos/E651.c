// 0109 · Grafos
// Exercício E651 · ★★☆

#include <stdio.h>

#define V 4

typedef struct {
    int de;
    int para;
} Rua;

int main(void) {
    Rua ruas[] = {{0, 1}, {1, 0}, {1, 2}, {2, 3}, {3, 0}, {0, 2}, {2, 0}};
    int total = (int)(sizeof ruas / sizeof ruas[0]);
    printf("Sentidos cadastrados: %d\n", total);

    int adj[V][V] = {0};
    for (int k = 0; k < total; k++) adj[ruas[k].de][ruas[k].para] = 1;

    int unica = 0, dupla = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (adj[i][j] && adj[j][i]) {
                printf("%c-%c: mão dupla\n", 'A' + i, 'A' + j);
                dupla++;
            } else if (adj[i][j]) {
                printf("%c-%c: mão única (%c -> %c)\n", 'A' + i, 'A' + j, 'A' + i, 'A' + j);
                unica++;
            } else if (adj[j][i]) {
                printf("%c-%c: mão única (%c -> %c)\n", 'A' + i, 'A' + j, 'A' + j, 'A' + i);
                unica++;
            }
        }
    }
    printf("Mão única: %d, mão dupla: %d\n", unica, dupla);
    return 0;
}
