// 0182 · Caminhos e ciclos
// Exercício E1089 · ★★☆
//
// Escreva um programa com o tipo Grafo (nome, v e a matriz m[MAXV][MAXV], em
// que m[a][b] conta as arestas paralelas entre a e b) e a função
// analisa(const Grafo *g), que diz se o grafo tem circuito euleriano,
// trajeto euleriano aberto (entre quais vértices) ou nenhum dos dois, e
// por quê. Confira a conexidade (por DFS) antes dos graus. Analise, nesta
// ordem, quatro grafos (arestas entre vértices numerados a partir de 0):
//
//   bairro (6 vértices): 0-1 0-2 1-2 1-3 1-5 2-4 2-5 3-4
//   casinha (5): 0-1 0-2 1-3 2-3 0-3 1-2 2-4 3-4
//   triângulos (6): 0-1 1-2 2-0 3-4 4-5 5-3
//   pontes (4): 0-1 0-1 0-2 0-2 0-3 1-3 2-3
//
//   Saída esperada:
//   bairro: circuito euleriano
//   casinha: trajeto euleriano de 0 a 1
//   triângulos: nenhum (desconexo)
//   pontes: nenhum (4 vértices ímpares)
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define MAXV 6

typedef struct {
    const char *nome;
    int v;
    int m[MAXV][MAXV];
} Grafo;

int main(void) {

    return 0;
}
