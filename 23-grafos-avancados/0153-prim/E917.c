// 0153 · Prim: a árvore que cresce
// Exercício E917 · ★★★
//
// Quatro casas de um sítio precisam de água. Cada casa pode cavar o
// próprio poço (Ana R$ 8 mil, Beto 5, Cida 9, Davi 7) ou receber cano de
// uma casa vizinha que já tem água. Os canos possíveis (R$ mil):
//
//   Ana-Beto 2, Beto-Cida 3, Cida-Davi 9, Ana-Davi 10, Ana-Cida 10
//
// Qual a solução mais barata? O truque: crie um vértice imaginário, a
// "Água" (índice 0), ligado a cada casa por uma aresta com o custo do poço
// dela. Cavar um poço vira "ligar a casa na Água", e o problema vira uma
// árvore geradora mínima comum. Escreva o programa com Prim a partir da
// Água e mostre a decisão de cada casa, na ordem em que entram.
//
//   Saída esperada:
//   Beto: cava poço (R$ 5 mil)
//   Ana: cano de Beto (R$ 2 mil)
//   Cida: cano de Beto (R$ 3 mil)
//   Davi: cava poço (R$ 7 mil)
//   Total: R$ 17 mil (2 poços)
//
// Dicas:
// 1. Monte uma matriz custo[V][V] com V = 5: os canos entre as casas
//    (índices 1 a 4) e custo[0][c] = custo[c][0] = poço da casa c.
// 2. No fim, quem tem pai[c] == 0 cavou poço; os outros receberam cano de
//    pai[c].
// 3. Resposta esperada: a saída acima. O Davi fica com o próprio poço
//    (7), mais barato que qualquer cano até ele (9 ou 10).
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define N 4       // casas
#define V (N + 1) // + o vértice imaginário "Água" (índice 0)
#define INFINITO INT_MAX

int main(void) {
    const char *nomes[V] = {"Água", "Ana", "Beto", "Cida", "Davi"};
    int poco[N] = {8, 5, 9, 7}; // custo de cavar um poço em cada casa (R$ mil)
    int canos[][3] = {{1, 2, 2}, {2, 3, 3}, {3, 4, 9}, {1, 4, 10}, {1, 3, 10}};
    (void)nomes; // apague estas três linhas
    (void)poco;
    (void)canos;

    return 0;
}
