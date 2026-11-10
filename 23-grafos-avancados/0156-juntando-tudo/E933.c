// 0156 · Juntando tudo: o assistente do calouro
// Exercício E933 · ★★☆
//
// O governo do estado vai asfaltar o mínimo de estradas que ligue as cinco
// regiões (árvore geradora mínima). Um deputado reclama: "da Capital até a
// Serra, a viagem vai ficar bem mais longa". As regiões (índices 0 a 4) são
// Capital, Agreste, Sertão, Litoral e Serra. As estradas possíveis (km, mão
// dupla), na ordem da lista:
//
//   Capital-Litoral 3, Capital-Agreste 7, Litoral-Agreste 5,
//   Agreste-Sertão 6, Litoral-Serra 9, Serra-Sertão 4, Capital-Serra 10
//
// Escreva o programa: monte a árvore mínima com Kruskal (mostre as estradas na
// ordem em que entram e o total), guarde as estradas da árvore numa segunda
// matriz e rode o Floyd-Warshall nas duas matrizes para comparar a viagem
// Capital -> Serra.
//
//   Saída esperada:
//   Rede mínima: Capital-Litoral, Serra-Sertão, Litoral-Agreste, Agreste-Sertão (18 km)
//   Capital -> Serra pela rede mínima: 18 km
//   Capital -> Serra pelo melhor caminho: 10 km
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define INFINITO 1000000000

int main(void) {

    return 0;
}
