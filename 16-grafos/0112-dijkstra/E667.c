// 0112 · Dijkstra: caminho mínimo
// Exercício E667 · ★☆☆
//
// Um centro de distribuição entrega em quatro bairros (CD 0, A 1, B 2, C 3 e D
// 4). As ruas são de mão dupla, com pesos em km: CD-A 7, CD-B 2, B-A 3, B-C 8,
// A-C 1, A-D 6 e C-D 2. Escreva o Dijkstra a partir do CD, com matriz de pesos,
// dist[] e anterior[], e imprima o teste de mesa: depois de relaxar os
// vizinhos de cada vértice fixado, mostre quem foi fixado e o vetor dist
// inteiro (- para INFINITO). No fim, mostre o caminho até D e a distância.
//
//   Saída esperada:
//   Fixa CD: dist = 0 7 2 - -
//   Fixa B: dist = 0 5 2 10 -
//   Fixa A: dist = 0 5 2 6 11
//   Fixa C: dist = 0 5 2 6 8
//   Fixa D: dist = 0 5 2 6 8
//   Caminho até D: CD -> B -> A -> C -> D (8 km)
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INFINITO INT_MAX

int main(void) {

    return 0;
}
