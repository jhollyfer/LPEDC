// 0154 · Bellman-Ford: pesos negativos
// Exercício E922 · ★★☆
//
// Num jogo, passar por um portal custa créditos, mas o portal da Caverna para a
// Floresta DEVOLVE 4 créditos (custo -4). As salas (índices 0 a 4) são Início,
// Floresta, Caverna, Castelo e Saída, e os portais, de mão única:
//
//   Início -> Floresta 2   Início -> Caverna 5   Caverna -> Floresta -4
//   Floresta -> Castelo 6  Castelo -> Saída 1    Caverna -> Castelo 9
//
// Guarde os custos numa matriz custo[][] (0 = sem portal) e escreva dijkstra (o
// do assunto 0112, O(V²), que nunca reabre um vértice já fixo) e bellman_ford,
// ambos a partir do Início. Compare as duas respostas para cada sala e marque
// as que o Dijkstra erra.
//
//   Saída esperada:
//   Floresta: Dijkstra 2, Bellman-Ford 1 (Dijkstra errou)
//   Caverna: Dijkstra 5, Bellman-Ford 5
//   Castelo: Dijkstra 8, Bellman-Ford 7 (Dijkstra errou)
//   Saída: Dijkstra 9, Bellman-Ford 8 (Dijkstra errou)
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define INFINITO 1000000000

int main(void) {

    return 0;
}
