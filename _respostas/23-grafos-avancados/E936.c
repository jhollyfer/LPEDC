// 0156 · Juntando tudo: o assistente do calouro
// Exercício E936 · ★★★

#include <stdio.h>

#define V 6
#define K 3 // clientes do dia
#define INFINITO 1000000000

const char *lugares[V] = {"Loja", "Ana", "Bruno", "Carla", "Praça", "Ponte"};
int d[V][V];
int clientes[K] = {1, 2, 3};
int melhor = INFINITO, melhor_ordem[K];

// permutações por troca (assunto 0126): fixa a posição pos e tenta cada cliente nela
void tenta(int pos) {
    if (pos == K) {
        int total = d[0][clientes[0]];
        for (int i = 0; i + 1 < K; i++) total += d[clientes[i]][clientes[i + 1]];
        total += d[clientes[K - 1]][0]; // volta para a loja
        printf("Loja");
        for (int i = 0; i < K; i++) printf(" -> %s", lugares[clientes[i]]);
        printf(" -> Loja: %d min\n", total);
        if (total < melhor) {
            melhor = total;
            for (int i = 0; i < K; i++) melhor_ordem[i] = clientes[i];
        }
        return;
    }
    for (int i = pos; i < K; i++) {
        int t = clientes[pos];
        clientes[pos] = clientes[i];
        clientes[i] = t;
        tenta(pos + 1);
        clientes[i] = clientes[pos]; // desfaz a troca
        clientes[pos] = t;
    }
}

int main(void) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = (i == j) ? 0 : INFINITO;
    int ruas[][3] = {{0, 4, 4}, {0, 5, 6}, {4, 1, 3}, {4, 2, 5}, {5, 3, 2},
                     {1, 2, 4}, {2, 3, 3}, {1, 5, 7}, {0, 3, 12}};
    for (int r = 0; r < 9; r++) d[ruas[r][0]][ruas[r][1]] = d[ruas[r][1]][ruas[r][0]] = ruas[r][2];
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];

    tenta(0);
    printf("Melhor roteiro (%d min): Loja", melhor);
    for (int i = 0; i < K; i++) printf(" -> %s", lugares[melhor_ordem[i]]);
    printf(" -> Loja\n");
    return 0;
}
