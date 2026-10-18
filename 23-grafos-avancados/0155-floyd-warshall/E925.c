// 0155 · Floyd-Warshall: todos os pares
// Exercício E925 · ★☆☆
//
// Uma cooperativa tem quatro galpões: Milho, Leite, Frutas e Mel (índices
// 0 a 3). As estradas internas são de mão única, em km:
//
//   Milho -> Leite 8     Leite -> Frutas 3    Frutas -> Milho 4
//   Milho -> Mel 15      Frutas -> Mel 5      Mel -> Leite 2
//
// Escreva o Floyd-Warshall do zero e mostre a tabela de distâncias, uma
// linha por galpão de origem (nome com %-7s e cada número com %4d).
//
//   Saída esperada:
//   Milho     0   8  11  15
//   Leite     7   0   3   8
//   Frutas    4   7   0   5
//   Mel       9   2   5   0
//
// Dicas:
// 1. Comece com 0 na diagonal e INFINITO (1000000000) onde não há estrada.
//    Com esse INFINITO folgado, d[i][k] + d[k][j] cabe num int mesmo
//    quando os dois são infinitos.
// 2. Três laços: k por fora, depois i, depois j. No miolo,
//    d[i][j] = mínimo(d[i][j], d[i][k] + d[k][j]).
// 3. Resposta esperada: a saída acima. Milho -> Mel continua 15: passar por
//    Leite e Frutas daria 8 + 3 + 5 = 16.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 4
#define INFINITO 1000000000

int main(void) {

    return 0;
}
