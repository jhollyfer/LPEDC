// Lista · Módulo 16 · Grafos
// Exercício P1615 · ★★☆ · Dijkstra do centro de distribuição, com a rota
//
// Um centro de distribuição (CD) no Distrito Industrial de Manaus entrega em
// seis bairros. As ruas são de mão dupla, com a distância em km na matriz
// peso[][] do esqueleto (0 = não há rua direta).
//
// Escreva o Dijkstra O(V²), sem heap: a cada rodada, escolha o vértice NÃO
// FECHADO de menor dist, feche-o e relaxe as arestas que saem dele, guardando
// pi[]. Depois mostre, para cada bairro, a distância e a rota a partir do CD
// (use uma função recursiva para imprimir a rota na ordem certa).
//
//   Saída esperada:
//   Japiim        4 km: CD -> Japiim
//   Coroado       6 km: CD -> Japiim -> Coroado
//   Aleixo        9 km: CD -> Japiim -> Coroado -> Aleixo
//   Centro       13 km: CD -> Japiim -> Centro
//   Flores       15 km: CD -> Japiim -> Coroado -> Aleixo -> Flores
//   Ponta Negra  25 km: CD -> Japiim -> Coroado -> Aleixo -> Flores -> Ponta Negra
//
// Dicas:
// 1. dist[CD] = 0 e dist[v] = INF para os outros. São V rodadas, e cada uma
//    varre o vetor dist[] inteiro: O(V²), bom para grafos densos.
// 2. Relaxar u-v: se dist[u] + peso[u][v] < dist[v], então dist[v] =
//    dist[u] + peso[u][v] e pi[v] = u.
// 3. Para a rota: rota(v) chama rota(pi[v]) antes de imprimir v, se pi[v]
//    não é -1.
// 4. Resposta esperada: Ponta Negra a 25 km, por CD -> Japiim -> Coroado ->
//    Aleixo -> Flores -> Ponta Negra; o Centro sai mais perto pelo Japiim
//    (13 km) do que pelo Aleixo (14 km).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

#define V 7

const char *nomes[V] = {"CD", "Japiim", "Coroado", "Aleixo", "Centro", "Flores", "Ponta Negra"};
int peso[V][V];

int main(void) {
    int ruas[][3] = {{0, 1, 4}, {0, 2, 7}, {1, 2, 2}, {1, 4, 9}, {2, 3, 3}, {3, 4, 5},
                     {3, 5, 6}, {4, 6, 14}, {5, 6, 10}, {4, 5, 4}};
    for (int k = 0; k < 10; k++) peso[ruas[k][0]][ruas[k][1]] = peso[ruas[k][1]][ruas[k][0]] = ruas[k][2];

    return 0;
}
