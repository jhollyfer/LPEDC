// 0109 · Grafos
// Exercício E652 · ★★☆

#include <stdio.h>

#define V 4

int main(void) {
    const char *nomes[V] = {"Ana", "Beto", "Cris", "Davi"};
    int adj[V][V] = {0};
    int duplas[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}};

    for (int k = 0; k < 4; k++) {
        int a = duplas[k][0];
        int b = duplas[k][1];
        adj[a][b] = 1;
        adj[b][a] = 1; // não dirigido: os dois sentidos
    }

    int soma = 0;
    for (int i = 0; i < V; i++) {
        int grau = 0;
        for (int j = 0; j < V; j++) grau += adj[i][j];
        printf("%s estuda com %d pessoa(s)\n", nomes[i], grau);
        soma += grau;
    }
    printf("Soma dos graus: %d\n", soma);
    return 0;
}
