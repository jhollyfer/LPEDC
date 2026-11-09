// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2308 · ★☆☆ · Bellman-Ford rodada a rodada
//
// O app de corrida dá um cupom no trecho Terminal -> Shopping (custo
// R$ -2). Os trechos, de mão única, estão na lista do main numa ordem ruim
// de propósito para o algoritmo: os trechos que saem da Casa vêm por último.
//
//   Casa -> Shopping 8, Casa -> Terminal 5, Terminal -> Shopping -2,
//   Shopping -> Faculdade 4, Terminal -> Faculdade 9,
//   Faculdade -> Estágio 3, Shopping -> Estágio 10
//
// Complete o laço das rodadas: em cada uma, relaxe os trechos na ordem da
// lista; se nada mudou, mostre que parou e saia; se mudou, mostre o vetor
// dist com a função mostra (já pronta). Faça no máximo V - 1 rodadas.
//
//   Saída esperada:
//   rodada 0:   0   -   -   -   -
//   rodada 1:   0   8   5   -   -
//   rodada 2:   0   3   5  12  18
//   rodada 3:   0   3   5   7  13
//   rodada 4:   0   3   5   7  10
//
// Dicas:
// 1. Relaxar: se dist[de] não é INF e dist[de] + custo < dist[para],
//    atualize e marque mudou = true.
// 2. Cada rodada empurra a informação uma aresta para a frente. Com a pior
//    ordem, o caminho Casa -> Terminal -> Shopping -> Faculdade -> Estágio,
//    de 4 trechos, precisa das 4 rodadas.
// 3. Resposta esperada: no fim, Shopping R$ 3, Terminal 5, Faculdade 7 e
//    Estágio 10, todos na rodada 4.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define E 7
#define INF INT_MAX

typedef struct {
    int de, para, custo;
} Trecho;

const char *pontos[V] = {"Casa", "Shopping", "Terminal", "Faculdade", "Estágio"};

void mostra(int rodada, const int dist[]) {
    printf("rodada %d:", rodada);
    for (int v = 0; v < V; v++) {
        if (dist[v] == INF) printf("   -");
        else printf(" %3d", dist[v]);
    }
    printf("\n");
}

int main(void) {
    Trecho t[E] = {{3, 4, 3}, {1, 3, 4}, {1, 4, 10}, {2, 1, -2}, {2, 3, 9}, {0, 1, 8}, {0, 2, 5}};
    int dist[V];
    for (int v = 0; v < V; v++) dist[v] = INF;
    dist[0] = 0;
    mostra(0, dist);
    (void)t; // apague esta linha e escreva as rodadas

    return 0;
}
