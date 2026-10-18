// 0154 · Bellman-Ford: pesos negativos
// Exercício E922 · ★★☆
//
// Num jogo, passar por um portal custa créditos, mas o portal da Caverna
// para a Floresta DEVOLVE 4 créditos (custo -4). O programa já tem o
// Dijkstra do assunto 0112 pronto. Escreva a função bellman_ford, usando a
// mesma matriz custo[][] (as arestas são as casas com custo diferente de 0),
// e compare as duas respostas.
//
//   Saída esperada:
//   Floresta: Dijkstra 2, Bellman-Ford 1 (Dijkstra errou)
//   Caverna: Dijkstra 5, Bellman-Ford 5
//   Castelo: Dijkstra 8, Bellman-Ford 7 (Dijkstra errou)
//   Saída: Dijkstra 9, Bellman-Ford 8 (Dijkstra errou)
//
// Dicas:
// 1. Com matriz, "passar por todas as arestas" vira dois laços (u e v) e
//    o teste custo[u][v] != 0. Uma rodada custa O(V²); o total, O(V³).
// 2. O Dijkstra fixa a Floresta com 2 antes de examinar a Caverna (5). Ele
//    nunca descobre que Início -> Caverna -> Floresta custa 5 - 4 = 1, e o
//    erro se espalha para Castelo e Saída.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (escreva bellman_ford):

#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INFINITO 1000000000

const char *salas[V] = {"Início", "Floresta", "Caverna", "Castelo", "Saída"};
int custo[V][V]; // créditos para passar de uma sala a outra; 0 = sem portal

void dijkstra(int dist[]) {
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
            if (custo[u][v] && !fixo[v] && dist[u] + custo[u][v] < dist[v]) dist[v] = dist[u] + custo[u][v];
    }
}

void bellman_ford(int dist[]) {
    for (int v = 0; v < V; v++) dist[v] = INFINITO; // complete a partir daqui
}

int main(void) {
    int portais[][3] = {{0, 1, 2}, {0, 2, 5}, {2, 1, -4}, {1, 3, 6}, {3, 4, 1}, {2, 3, 9}};
    for (int k = 0; k < 6; k++) custo[portais[k][0]][portais[k][1]] = portais[k][2];

    int d[V], b[V];
    dijkstra(d);
    bellman_ford(b);
    for (int v = 1; v < V; v++)
        printf("%s: Dijkstra %d, Bellman-Ford %d%s\n", salas[v], d[v], b[v],
               d[v] != b[v] ? " (Dijkstra errou)" : "");
    return 0;
}
