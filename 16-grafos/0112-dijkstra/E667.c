// 0112 · Dijkstra: caminho mínimo
// Exercício E667 · ★☆☆
//
// Um centro de distribuição (CD) entrega em quatro bairros, A, B, C e D. As
// ruas são de mão dupla e os pesos são km:
//
//   CD-A 7, CD-B 2, B-A 3, B-C 8, A-C 1, A-D 6, C-D 2
//
// O esqueleto já monta o grafo e roda o Dijkstra a partir do CD, mas não
// mostra nada. Faça o programa imprimir o próprio teste de mesa: depois de
// relaxar os vizinhos de cada vértice fixado, mostre quem foi fixado e o
// vetor dist inteiro (use - para INFINITO). No fim, mostre o caminho até D
// seguindo anterior[] e a distância.
//
//   Saída esperada:
//   Fixa CD: dist = 0 7 2 - -
//   Fixa B: dist = 0 5 2 10 -
//   Fixa A: dist = 0 5 2 6 11
//   Fixa C: dist = 0 5 2 6 8
//   Fixa D: dist = 0 5 2 6 8
//   Caminho até D: CD -> B -> A -> C -> D (8 km)
//
// Dicas:
// 1. O printf da linha vai no fim do corpo do for (passo), depois do laço
//    que relaxa. Um laço interno imprime dist[v] ou "-".
// 2. O caminho sai de trás para frente: guarde num vetor seguindo
//    anterior[] a partir de D e imprima do fim para o começo.
// 3. Resposta esperada: a saída acima. Repare no A, que cai de 7 para 5
//    quando o B é fixado, e no D, que cai de 11 para 8.
//
// Escreva sua resposta abaixo (complete o código):

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INFINITO INT_MAX

int main(void) {
    const char *nomes[V] = {"CD", "A", "B", "C", "D"};
    int km[V][V] = {0};
    int ruas[][3] = {{0, 1, 7}, {0, 2, 2}, {2, 1, 3}, {2, 3, 8}, {1, 3, 1}, {1, 4, 6}, {3, 4, 2}};
    for (int k = 0; k < 7; k++) {
        km[ruas[k][0]][ruas[k][1]] = ruas[k][2];
        km[ruas[k][1]][ruas[k][0]] = ruas[k][2];
    }

    int dist[V], anterior[V];
    bool fixo[V] = {false};
    for (int v = 0; v < V; v++) {
        dist[v] = INFINITO;
        anterior[v] = -1;
    }
    dist[0] = 0;

    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!fixo[v] && dist[v] != INFINITO && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1) break;
        fixo[u] = true;
        for (int v = 0; v < V; v++)
            if (km[u][v] && !fixo[v] && dist[u] + km[u][v] < dist[v]) {
                dist[v] = dist[u] + km[u][v];
                anterior[v] = u;
            }
    }
    (void)nomes;    // apague esta linha quando usar nomes
    (void)anterior; // apague esta linha quando usar anterior

    return 0;
}
