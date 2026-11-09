// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2914 · ★★☆ · Pontes com lista de adjacência
//
// Uma rede de oito servidores (0 a 7) tem os cabos:
//
//   0-1, 1-2, 2-0, 2-3, 3-4, 4-5, 5-3, 5-6, 6-7
//
// Monte o grafo como LISTA de adjacência dinâmica (cada vértice com um vetor
// alocado com malloc do tamanho do seu grau) e rode a DFS com tin e low a
// partir do 0. Mostre as pontes, na ordem em que a DFS as acha, e as
// articulações, em ordem de índice. Libere tudo no fim.
//
//   Saída esperada:
//   Ponte: 6-7
//   Ponte: 5-6
//   Ponte: 2-3
//   Articulações: 2 3 5 6
//
// Dicas:
// 1. Conte os graus primeiro, aloque vizinho[u] = malloc(grau[u] * sizeof(int))
//    e depois preencha. Confira NULL.
// 2. As regras são as do texto: ponte se low[v] > tin[u]; articulação se
//    low[v] >= tin[u] fora da raiz, ou raiz com 2 ou mais filhos.
// 3. Resposta esperada: a saída acima. Com lista, a DFS custa O(V + E) em vez
//    de O(V²).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
