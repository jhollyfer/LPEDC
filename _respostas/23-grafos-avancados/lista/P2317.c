// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2317 · ★★☆ · A rota do BRT

#include <stdio.h>

#define V 5
#define INF 1000000

const char *estacoes[V] = {"Terminal", "Centro", "Rodoviária", "Aeroporto", "Universidade"};
int d[V][V];
int prox[V][V]; // prox[i][j]: a primeira estação depois de i no caminho até j

void floyd(void) {
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    prox[i][j] = prox[i][k]; // vai para k pelo mesmo primeiro passo
                }
}

void rota(int a, int b) {
    printf("%s -> %s (%d min):", estacoes[a], estacoes[b], d[a][b]);
    for (int x = a; x != b; x = prox[x][b]) printf(" %s ->", estacoes[x]);
    printf(" %s\n", estacoes[b]);
}

int main(void) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) {
            d[i][j] = i == j ? 0 : INF;
            prox[i][j] = -1;
        }
    int linhas[][3] = {{0, 1, 7}, {1, 2, 4}, {0, 2, 15}, {2, 3, 6}, {1, 4, 9}, {4, 3, 3}, {0, 4, 20}};
    for (int k = 0; k < 7; k++) {
        int a = linhas[k][0], b = linhas[k][1];
        d[a][b] = d[b][a] = linhas[k][2];
        prox[a][b] = b;
        prox[b][a] = a;
    }
    floyd();
    rota(0, 3);
    rota(4, 2);
    rota(3, 0);
    rota(2, 4);
    return 0;
}
