// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2923 · ★★★ · O carteiro e as duas esquinas ímpares

#include <stdio.h>

#define V 6
#define E 8
#define INF 1000000

int main(void) {
    int r[E][3] = {{0, 1, 100}, {1, 2, 80}, {2, 3, 120}, {3, 0, 90},
                   {2, 4, 60}, {4, 5, 70}, {5, 2, 50}, {1, 4, 200}};
    int d[V][V], grau[V] = {0}, soma = 0;
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) d[a][b] = a == b ? 0 : INF;
    for (int k = 0; k < E; k++) {
        int a = r[k][0], b = r[k][1];
        d[a][b] = d[b][a] = r[k][2];
        grau[a]++, grau[b]++;
        soma += r[k][2];
    }
    int imp[V], n = 0;
    for (int u = 0; u < V; u++)
        if (grau[u] % 2) imp[n++] = u;
    if (n != 2) {
        printf("Este programa trata só o caso de 2 esquinas ímpares\n");
        return 0;
    }
    for (int k = 0; k < V; k++)
        for (int a = 0; a < V; a++)
            for (int b = 0; b < V; b++)
                if (d[a][k] + d[k][b] < d[a][b]) d[a][b] = d[a][k] + d[k][b];
    printf("Ruas: %d m\n", soma);
    printf("Esquinas ímpares: %d e %d\n", imp[0], imp[1]);
    printf("Extra: %d m\n", d[imp[0]][imp[1]]);
    printf("Total: %d m\n", soma + d[imp[0]][imp[1]]);
    return 0;
}
