// 0187 · Reduções
// Exercício E1120 · ★★☆
//
// Generalize a construção do A373. Escreva a função
// void reduz(const char *nome, int m, const int f[][3]), que recebe uma
// fórmula 3-CNF com m cláusulas, monta o grafo da redução (um vértice por
// literal, aresta entre literais de cláusulas diferentes que não se
// contradizem), conta vértices e arestas e procura uma clique com um
// vértice de cada cláusula. Teste nas duas fórmulas:
//
//   F1: (x1 ou x2 ou x3) (não x1 ou não x2 ou x3)
//       (x1 ou não x2 ou não x3) (não x1 ou x2 ou não x3)
//   F2: as 8 cláusulas possíveis com x1, x2, x3 (cada uma com ou sem "não")
//
//   Saída esperada:
//   F1: 12 vértices, 42 arestas, clique de 4? sim (satisfatível)
//   F2: 24 vértices, 204 arestas, clique de 8? não (insatisfatível)
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
