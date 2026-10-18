// 0109 · Grafos
// Exercício E654 · ★★★

#include <stdio.h>

#define V 6

int main(void) {
    const char *nomes[V] = {"Ana", "Bia", "Caio", "Duda", "Edu", "Fabi"};
    int adj[V][V] = {0};
    int amizades[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 5}, {4, 5}};
    int total = (int)(sizeof amizades / sizeof amizades[0]);

    for (int k = 0; k < total; k++) {
        adj[amizades[k][0]][amizades[k][1]] = 1;
        adj[amizades[k][1]][amizades[k][0]] = 1;
    }

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (adj[i][j]) continue; // já são amigos
            int comum = 0;
            for (int k = 0; k < V; k++) comum += adj[i][k] && adj[k][j];
            if (comum >= 2) printf("%s e %s: %d amigos em comum\n", nomes[i], nomes[j], comum);
        }
    }
    return 0;
}
