// 0052 · Ponteiros e vetores
// Exercício E311 · ★★★
//
// A loja tem 3 filiais e anotou as vendas de 4 semanas numa matriz
//
//   int vendas[3][4] = {
//       {12, 15, 9, 20},
//       {7, 11, 14, 10},
//       {18, 6, 13, 16},
//   };
//
// Como a matriz é uma fila só de 12 ints na memória (assunto 0044), dá para
// percorrê-la com UM ponteiro e UM laço. Faça isso: some tudo e descubra
// qual filial vendeu mais, calculando a linha de cada elemento pela
// distância (p - inicio) / 4.
//
//   Saída esperada:
//   Total: 151
//   Filial 0: 56
//   Filial 1: 42
//   Filial 2: 53
//   Campeã: filial 0
//
// Dicas:
// 1. int *inicio = &vendas[0][0]; o laço vai de p = inicio até
//    p < inicio + 12.
// 2. Guarde os totais num vetor int filial[3] = {0}; e some *p em
//    filial[(p - inicio) / 4].
// 3. Resposta esperada: total 151; filiais 56, 42 e 53; campeã filial 0.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
