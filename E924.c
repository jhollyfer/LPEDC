// 0154 · Bellman-Ford: pesos negativos
// Exercício E924 · ★★★
//
// Você quer voar de Recife a Curitiba, mas odeia conexões. As cidades (índices
// 0 a 4) são Recife, Salvador, Brasília, São Paulo e Curitiba. Os voos (mão
// única, preço em R$):
//
//   Recife -> Curitiba 900      Recife -> Salvador 200
//   Salvador -> Brasília 250    Brasília -> Curitiba 300
//   Recife -> Brasília 500      Salvador -> São Paulo 350
//   São Paulo -> Curitiba 150   Brasília -> São Paulo 120
//
// Escreva mais_barato(origem, destino, k): o menor preço usando NO MÁXIMO k
// voos. Use o Bellman-Ford com k rodadas, mas em cada rodada relaxe lendo uma
// CÓPIA da dist da rodada anterior: assim a rodada r acrescenta no máximo um
// voo a cada caminho. Mostre o resultado para k de 1 a 3.
//
//   Saída esperada:
//   Até 1 trecho: R$ 900
//   Até 2 trechos: R$ 800
//   Até 3 trechos: R$ 700
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define INFINITO 1000000000

int main(void) {

    return 0;
}
