// 0155 · Floyd-Warshall: todos os pares
// Exercício E926 · ★☆☆

#include <limits.h>
#include <stdio.h>

#define V 5
#define INFINITO INT_MAX

const char *filiais[V] = {"SP", "RJ", "BH", "POA", "REC"};

void floyd(int d[V][V]) {
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] != INFINITO && d[k][j] != INFINITO && d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
}

int main(void) {
    int d[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = (i == j) ? 0 : INFINITO;
    int malotes[][3] = {{0, 1, 1}, {1, 2, 2}, {2, 0, 2}, {0, 3, 3}, {3, 0, 4}, {2, 3, 4}};
    for (int m = 0; m < 6; m++) d[malotes[m][0]][malotes[m][1]] = malotes[m][2];

    floyd(d);

    printf("     ");
    for (int j = 0; j < V; j++) printf("%4s", filiais[j]);
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%-5s", filiais[i]);
        for (int j = 0; j < V; j++) {
            if (d[i][j] == INFINITO) printf("%4s", "-");
            else printf("%4d", d[i][j]);
        }
        printf("\n");
    }
    return 0;
}
