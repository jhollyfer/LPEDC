// 0155 · Floyd-Warshall: todos os pares
// Exercício E927 · ★★☆

#include <stdio.h>

#define V 6
#define INFINITO 1000000000

int main(void) {
    const char *bairros[V] = {"Vila Rica", "Jardim", "Centro", "Lagoa", "Bosque", "Porto"};
    int d[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = (i == j) ? 0 : INFINITO;
    int ruas[][3] = {{0, 1, 4}, {1, 2, 3}, {2, 3, 5}, {3, 4, 2},
                     {2, 4, 6}, {4, 5, 7}, {1, 3, 9}, {0, 5, 20}};
    for (int r = 0; r < 8; r++) {
        d[ruas[r][0]][ruas[r][1]] = ruas[r][2];
        d[ruas[r][1]][ruas[r][0]] = ruas[r][2];
    }

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];

    int melhor = 0, menor_pior = INFINITO;
    for (int i = 0; i < V; i++) {
        int pior = 0, longe = i; // o bairro mais distante de i
        for (int j = 0; j < V; j++)
            if (d[i][j] > pior) {
                pior = d[i][j];
                longe = j;
            }
        printf("%s: o mais longe é %s, a %d km\n", bairros[i], bairros[longe], pior);
        if (pior < menor_pior) {
            menor_pior = pior;
            melhor = i;
        }
    }
    printf("Melhor bairro para o posto: %s (ninguém fica a mais de %d km)\n", bairros[melhor], menor_pior);
    return 0;
}
