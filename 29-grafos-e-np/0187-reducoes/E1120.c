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
// Dicas:
// 1. O vértice a corresponde ao literal f[a / 3][a % 3]; a / 3 é a
//    cláusula dele. Use uma matriz global adj[24][24].
// 2. Para procurar a clique, conte em base 3 com m algarismos (3^m
//    escolhas): o algarismo c diz qual literal da cláusula c entra.
// 3. Resposta esperada: a saída acima. F2 é insatisfatível: cada
//    atribuição dos três x torna falsa exatamente uma das 8 cláusulas.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
