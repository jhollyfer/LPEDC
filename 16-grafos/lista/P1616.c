// Lista · Módulo 16 · Grafos
// Exercício P1616 · ★★☆ · Conserte o Dijkstra das balsas
//
// Conserte o programa. Ele calcula o menor tempo de viagem de balsa, em
// horas, saindo de Manaus para cidades do Amazonas (trechos de ida e volta,
// peso 0 = não há balsa direta). O código tem DOIS erros de propósito: um na
// escolha do próximo vértice e outro no relaxamento. Ele termina e não tem
// erro de memória, mas a resposta está errada:
//
//   Saída que aparece:
//   Manacapuru   3 h
//   Itacoatiara  6 h
//   Parintins   18 h
//   Coari       30 h
//   Tefe         0 h
//
// Depois do conserto:
//
//   Saída esperada:
//   Manacapuru   3 h
//   Itacoatiara  6 h
//   Parintins   16 h
//   Coari       23 h
//   Tefe        35 h
//
// Dicas:
// 1. Olhe a escolha do mínimo: um vértice já fechado continua com o menor
//    dist para sempre. Se ele puder ser escolhido de novo, o algoritmo nunca
//    sai do lugar.
// 2. Na matriz, peso 0 quer dizer "não há aresta". Um relaxamento que não
//    testa isso acha que existe uma balsa de 0 horas entre quaisquer duas
//    cidades.
// 3. Um bom teste: Tefe não tem balsa direta de Manaus. Se aparecer com 0 h,
//    o relaxamento está usando uma aresta que não existe.
// 4. Resposta esperada: Manacapuru 3 h, Itacoatiara 6 h, Parintins 16 h,
//    Coari 23 h, Tefe 35 h.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define V 6
#define INF 1000000

const char *nomes[V] = {"Manaus", "Manacapuru", "Itacoatiara", "Parintins", "Coari", "Tefe"};
int peso[V][V];

int main(void) {
    int trechos[][3] = {{0, 1, 3}, {0, 2, 6}, {2, 3, 10}, {0, 3, 18}, {1, 4, 20}, {4, 5, 12}, {0, 4, 30}};
    for (int k = 0; k < 7; k++) peso[trechos[k][0]][trechos[k][1]] = peso[trechos[k][1]][trechos[k][0]] = trechos[k][2];

    int dist[V];
    bool fechado[V] = {false};
    for (int v = 0; v < V; v++) dist[v] = INF;
    dist[0] = 0;
    for (int rodada = 0; rodada < V; rodada++) {
        int u = 0;
        for (int v = 1; v < V; v++)
            if (dist[v] < dist[u]) u = v;
        fechado[u] = true;
        for (int v = 0; v < V; v++)
            if (!fechado[v] && dist[u] + peso[u][v] < dist[v]) dist[v] = dist[u] + peso[u][v];
    }
    for (int v = 1; v < V; v++) printf("%-11s %2d h\n", nomes[v], dist[v]);
    return 0;
}
