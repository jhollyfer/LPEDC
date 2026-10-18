// 0113 · Juntando tudo: a central de entregas
// Exercício E673 · ★☆☆

#include <stdio.h>

#define MAX 20

int main(void) {
    int n, e;
    if (scanf("%d %d", &n, &e) != 2 || n < 1 || n > MAX || e < 0) {
        printf("Cabeçalho inválido\n");
        return 1;
    }
    int adj[MAX][MAX] = {0};
    for (int k = 0; k < e; k++) {
        int a, b;
        if (scanf("%d %d", &a, &b) != 2) {
            printf("Faltou aresta\n");
            return 1;
        }
        if (a < 0 || a >= n || b < 0 || b >= n || a == b) {
            printf("Aresta inválida: %d %d\n", a, b);
            continue;
        }
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    for (int v = 0; v < n; v++) {
        int grau = 0;
        printf("%d:", v);
        for (int w = 0; w < n; w++)
            if (adj[v][w]) {
                printf(" %d", w);
                grau++;
            }
        printf(" (grau %d)\n", grau);
    }
    return 0;
}
