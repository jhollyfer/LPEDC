// A309 · Floyd-Warshall com rota: o mapa do metrô

#include <stdio.h>

#define V 6
#define INFINITO 1000000000

const char *estacoes[V] = {"Sé", "Luz", "Brás", "Paraíso", "Consolação", "Pinheiros"};
int d[V][V];    // minutos
int prox[V][V]; // prox[i][j]: a primeira estação depois de i no melhor caminho até j

void rota(int i, int j) {
    printf("%s", estacoes[i]);
    while (i != j) {
        i = prox[i][j]; // anda um passo
        printf(" -> %s", estacoes[i]);
    }
}

int main(void) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) {
            d[i][j] = (i == j) ? 0 : INFINITO;
            prox[i][j] = (i == j) ? i : -1;
        }
    int trilhos[][3] = {{0, 1, 3}, {0, 2, 4}, {0, 3, 5}, {3, 4, 4}, {4, 5, 6}, {1, 4, 9}, {3, 5, 12}};
    for (int t = 0; t < 7; t++) {
        int a = trilhos[t][0], b = trilhos[t][1];
        d[a][b] = d[b][a] = trilhos[t][2]; // o metrô anda nos dois sentidos
        prox[a][b] = b;
        prox[b][a] = a;
    }

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] != INFINITO && d[k][j] != INFINITO && d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    prox[i][j] = prox[i][k]; // para ir a j por k, o primeiro passo é o de ir a k
                }

    int pedidos[][2] = {{2, 5}, {1, 5}, {5, 1}};
    for (int p = 0; p < 3; p++) {
        int i = pedidos[p][0], j = pedidos[p][1];
        printf("%d min: ", d[i][j]);
        rota(i, j);
        printf("\n");
    }
    return 0;
}
// Saída:
// 19 min: Brás -> Sé -> Paraíso -> Consolação -> Pinheiros
// 15 min: Luz -> Consolação -> Pinheiros
// 15 min: Pinheiros -> Consolação -> Luz
//
// Uma matriz de V × V próximos passos guarda TODAS as rotas: em vez de
// guardar V² caminhos inteiros, cada casa guarda só um número.
