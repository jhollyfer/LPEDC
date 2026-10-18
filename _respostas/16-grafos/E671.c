// 0112 · Dijkstra: caminho mínimo
// Exercício E671 · ★★★
//
// Resposta: o laço de escolha aceitava qualquer vértice não fixo, mesmo com
// dist == INFINITO. Depois de fixar SP, Rio e BH, ele escolhia Manaus
// (dist = INT_MAX) e, no relaxamento, dist[u] + preco[u][v] fazia
// INT_MAX + 300: estouro de int com sinal, comportamento indefinido. Na
// prática deu um número negativo, menor que INFINITO, e Belém "ganhou" um
// preço absurdo. Conserto: só escolher u com dist finita e parar quando não
// houver nenhum.

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INFINITO INT_MAX

int main(void) {
    const char *nomes[V] = {"SP", "Rio", "BH", "Manaus", "Belém"};
    int preco[V][V] = {0};
    int voos[][3] = {{0, 1, 200}, {0, 2, 250}, {1, 2, 180}, {3, 4, 300}};
    for (int k = 0; k < 4; k++) {
        preco[voos[k][0]][voos[k][1]] = voos[k][2];
        preco[voos[k][1]][voos[k][0]] = voos[k][2];
    }

    int dist[V];
    bool fixo[V];
    for (int v = 0; v < V; v++) {
        dist[v] = INFINITO;
        fixo[v] = false;
    }
    dist[0] = 0;

    for (int passo = 0; passo < V; passo++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!fixo[v] && dist[v] != INFINITO && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1) break; // o resto é inalcançável: nada de somar com INFINITO
        fixo[u] = true;
        for (int v = 0; v < V; v++)
            if (preco[u][v] && !fixo[v] && dist[u] + preco[u][v] < dist[v])
                dist[v] = dist[u] + preco[u][v];
    }

    for (int v = 1; v < V; v++) {
        if (dist[v] == INFINITO) printf("%s: sem voo\n", nomes[v]);
        else printf("%s: R$ %d\n", nomes[v], dist[v]);
    }
    return 0;
}
