// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2309 · ★☆☆ · Floyd-Warshall quadro a quadro

#include <stdio.h>

#define V 4
#define INF 1000000

const char *bairros[V] = {"Centro", "Adrianópolis", "Ponta Negra", "Cidade Nova"};
const char *siglas[V] = {"CEN", "ADR", "PNE", "CNO"};

void mostra(int d[V][V]) {
    printf("     ");
    for (int j = 0; j < V; j++) printf(" %4s", siglas[j]);
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%-5s", siglas[i]);
        for (int j = 0; j < V; j++) {
            if (d[i][j] >= INF) printf("    -");
            else printf(" %4d", d[i][j]);
        }
        printf("\n");
    }
}

void floyd(int d[V][V]) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
        printf("Depois de k = %s:\n", siglas[k]);
        mostra(d);
    }
}

int main(void) {
    int d[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = i == j ? 0 : INF;
    int ruas[][3] = {{0, 1, 10}, {1, 2, 25}, {0, 2, 40}, {2, 3, 15}, {3, 0, 20}, {1, 3, 30}};
    for (int k = 0; k < 6; k++) d[ruas[k][0]][ruas[k][1]] = ruas[k][2];

    printf("Início:\n");
    mostra(d);
    floyd(d);
    return 0;
}
