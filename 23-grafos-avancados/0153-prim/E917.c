// 0153 · Prim: a árvore que cresce
// Exercício E917 · ★★★
//
// Quatro casas de um sítio precisam de água. Cada casa pode cavar o próprio
// poço (Ana R$ 8 mil, Beto 5, Cida 9, Davi 7) ou receber cano de uma casa
// vizinha que já tem água. Os canos possíveis (R$ mil):
//
//   Ana-Beto 2, Beto-Cida 3, Cida-Davi 9, Ana-Davi 10, Ana-Cida 10
//
// Qual a solução mais barata? Crie um vértice imaginário, a "Água" (índice 0),
// ligado a cada casa por uma aresta com o custo do poço dela: cavar um poço
// vira "ligar a casa na Água", e o problema vira uma árvore geradora mínima
// comum. Escreva o programa com Prim a partir da Água e mostre a decisão de
// cada casa, na ordem em que entram.
//
//   Saída esperada:
//   Beto: cava poço (R$ 5 mil)
//   Ana: cano de Beto (R$ 2 mil)
//   Cida: cano de Beto (R$ 3 mil)
//   Davi: cava poço (R$ 7 mil)
//   Total: R$ 17 mil (2 poços)
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define INFINITO INT_MAX

int main(void) {

    return 0;
}
