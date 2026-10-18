// 0112 · Dijkstra: caminho mínimo
// Exercício E672 · ★★★
//
// Um app de entregas calcula o custo de cada trecho em reais (grafo
// dirigido). Um parceiro oferece cashback: o trecho B -> A DEVOLVE R$ 3, e o
// programador colocou peso -3 nele. Os trechos:
//
//   Base -> A 5, Base -> B 6, B -> A -3, A -> C 1
//
// O Dijkstra do esqueleto roda sem erro, mas dá a resposta errada. Estenda o
// programa em duas partes, depois das linhas que ele já imprime:
//
// Primeiro, a CONFERÊNCIA: percorra todas as arestas u -> v e mostre cada
// uma que ainda consegue encurtar dist[v] (dist[u] + custo < dist[v]). Num
// resultado certo, nenhuma aparece.
//
// Depois, o CERTO: calcule as distâncias de novo num vetor separado com o
// algoritmo de Bellman-Ford: comece com 0 na Base e INFINITO no resto e
// relaxe TODAS as arestas, repetindo isso V - 1 vezes, sem fixar ninguém.
//
//   Saída esperada:
//   A: R$ 5
//   B: R$ 6
//   C: R$ 6
//   Ainda encurta: B -> A (6 + -3 = 3 < 5)
//   Com Bellman-Ford:
//   A: R$ 3
//   B: R$ 6
//   C: R$ 4
//
// Dicas:
// 1. Simule o Dijkstra: fixa Base; A = 5, B = 6. O menor é A, que é FIXADO
//    com 5. Quando B é fixado e olha para A, A já está fixo: o código nem
//    tenta. Dijkstra supõe pesos NÃO negativos.
// 2. Na conferência e no Bellman-Ford, pule u com dist INFINITO antes de
//    somar (INT_MAX + peso estoura).
// 3. Bellman-Ford: três laços, volta de 0 a V-2, u e v. Um caminho mínimo
//    tem no máximo V - 1 arestas, e cada volta acerta pelo menos mais uma.
// 4. Resposta esperada: a saída acima. A = 3 (Base -> B -> A: 6 - 3) e
//    C = 4 (Base -> B -> A -> C).
//
// Escreva sua resposta abaixo (estenda o código):

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
