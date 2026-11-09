// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2317 · ★★☆ · A rota do BRT
//
// O BRT liga cinco estações (minutos, mão dupla). O programa já calcula a
// tabela de distâncias com Floyd-Warshall, mas o passageiro quer saber POR
// ONDE ir. Estenda: acrescente a matriz prox[i][j], a primeira estação
// depois de i no melhor caminho até j, atualize-a dentro do Floyd e
// escreva rota(a, b), que mostra o tempo e o caminho. Mostre as rotas
// Terminal -> Aeroporto, Universidade -> Rodoviária, Aeroporto -> Terminal
// e Rodoviária -> Universidade.
//
//   Saída esperada:
//   Terminal -> Aeroporto (17 min): Terminal -> Centro -> Rodoviária -> Aeroporto
//   Universidade -> Rodoviária (9 min): Universidade -> Aeroporto -> Rodoviária
//   Aeroporto -> Terminal (17 min): Aeroporto -> Rodoviária -> Centro -> Terminal
//   Rodoviária -> Universidade (9 min): Rodoviária -> Aeroporto -> Universidade
//
// Dicas:
// 1. No começo, prox[a][b] = b para cada linha direta (nos dois sentidos).
// 2. Quando i -> k -> j melhora, o primeiro passo de i até j passa a ser o
//    primeiro passo de i até k: prox[i][j] = prox[i][k].
// 3. Resposta esperada: Terminal -> Aeroporto em 17 min pelo Centro e pela
//    Rodoviária; a linha direta Terminal-Universidade (20) nunca é usada.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 5
#define INF 1000000

const char *estacoes[V] = {"Terminal", "Centro", "Rodoviária", "Aeroporto", "Universidade"};
int d[V][V];

void floyd(void) {
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
}

int main(void) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = i == j ? 0 : INF;
    int linhas[][3] = {{0, 1, 7}, {1, 2, 4}, {0, 2, 15}, {2, 3, 6}, {1, 4, 9}, {4, 3, 3}, {0, 4, 20}};
    for (int k = 0; k < 7; k++) {
        int a = linhas[k][0], b = linhas[k][1];
        d[a][b] = d[b][a] = linhas[k][2];
    }
    floyd();
    printf("Terminal -> Aeroporto: %d min\n", d[0][3]);
    return 0;
}
