// 0156 · Juntando tudo: o assistente do calouro
// Exercício E933 · ★★☆
//
// O governo do estado vai asfaltar o mínimo de estradas que ligue as cinco
// regiões (árvore geradora mínima). Um deputado reclama: "da Capital até a
// Serra, a viagem vai ficar bem mais longa". As estradas possíveis (km,
// mão dupla):
//
//   Capital-Litoral 3, Capital-Agreste 7, Litoral-Agreste 5,
//   Agreste-Sertão 6, Litoral-Serra 9, Serra-Sertão 4, Capital-Serra 10
//
// Escreva o programa: monte a árvore mínima com Kruskal (mostre as
// estradas na ordem em que entram e o total), guarde as estradas da árvore
// numa segunda matriz e rode o Floyd-Warshall nas duas matrizes para
// comparar a viagem Capital -> Serra.
//
//   Saída esperada:
//   Rede mínima: Capital-Litoral, Serra-Sertão, Litoral-Agreste, Agreste-Sertão (18 km)
//   Capital -> Serra pela rede mínima: 18 km
//   Capital -> Serra pelo melhor caminho: 10 km
//
// Dicas:
// 1. Comece as duas matrizes (todas e arvore) com 0 na diagonal e
//    INFINITO no resto. Grave todas as estradas em "todas" antes de
//    ordenar; em "arvore", só as que o Kruskal aceitar.
// 2. Uma função floyd(d) serve para as duas matrizes. Escreva cada estrada
//    aceita como "nomes[a]-nomes[b]", na ordem do vetor.
// 3. Resposta esperada: a saída acima. A árvore mínima não guarda caminhos
//    curtos: na rede mínima a Capital só chega à Serra dando a volta
//    Capital, Litoral, Agreste, Sertão, Serra (3 + 5 + 6 + 4).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define V 5
#define E 7
#define INFINITO 1000000000

typedef struct {
    int a, b, km;
} Estrada;

const char *cidades[V] = {"Capital", "Agreste", "Sertão", "Litoral", "Serra"};

int main(void) {
    Estrada e[E] = {{0, 3, 3}, {0, 1, 7}, {3, 1, 5}, {1, 2, 6}, {3, 4, 9}, {4, 2, 4}, {0, 4, 10}};
    (void)e; // apague esta linha

    return 0;
}
