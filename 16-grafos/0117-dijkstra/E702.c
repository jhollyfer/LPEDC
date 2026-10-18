// 0117 · Dijkstra: caminho mínimo
// Exercício E702 · ★★★
//
// Um app de entregas calcula o custo de cada trecho em reais (grafo
// dirigido). Um parceiro oferece cashback: o trecho B -> A DEVOLVE R$ 3, e o
// programador colocou peso -3 nele. Os trechos:
//
//   Base -> A 5, Base -> B 6, B -> A -3, A -> C 1
//
// a) Sem rodar, preveja o que o Dijkstra abaixo mostra.
// b) Calcule à mão o custo mínimo de verdade até A e até C.
// c) Explique por que o Dijkstra erra aqui. Qual hipótese do algoritmo foi
//    quebrada?
//
// Dicas:
// 1. Simule: fixa Base; A = 5, B = 6. O menor é A, que é FIXADO com 5.
// 2. Quando B é fixado e olha para A, A já está fixo: o código nem tenta.
//    E mesmo se tentasse, C já teria sido calculado com o A antigo.
// 3. Resposta esperada:
//    a) A: R$ 5 / B: R$ 6 / C: R$ 6
//    b) A = 3 (Base -> B -> A: 6 - 3) e C = 4 (Base -> B -> A -> C).
//    c) Dijkstra supõe pesos NÃO negativos: ao fixar o menor dist, assume que
//       nenhum caminho por outro vértice pode ficar mais barato, porque somar
//       pesos só aumenta. Com peso negativo, um caminho mais longo pode
//       ficar mais barato depois. (Para isso existe o algoritmo de
//       Bellman-Ford.)
//
// Escreva sua resposta abaixo (como comentário):

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 4
#define INFINITO INT_MAX

int main(void) {
    const char *nomes[V] = {"Base", "A", "B", "C"};
    int custo[V][V] = {0};
    int trechos[][3] = {{0, 1, 5}, {0, 2, 6}, {2, 1, -3}, {1, 3, 1}};
    for (int k = 0; k < 4; k++) custo[trechos[k][0]][trechos[k][1]] = trechos[k][2];

    int dist[V];
    bool fixo[V] = {false};
    for (int v = 0; v < V; v++) dist[v] = INFINITO;
    dist[0] = 0;

    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!fixo[v] && dist[v] != INFINITO && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1) break;
        fixo[u] = true;
        for (int v = 0; v < V; v++)
            if (custo[u][v] && !fixo[v] && dist[u] + custo[u][v] < dist[v])
                dist[v] = dist[u] + custo[u][v];
    }

    for (int v = 1; v < V; v++) printf("%s: R$ %d\n", nomes[v], dist[v]);
    return 0;
}
