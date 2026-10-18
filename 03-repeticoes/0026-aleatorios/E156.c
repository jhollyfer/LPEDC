// 0026 · Aleatórios
// Exercício E156 · ★★★
//
// Quantos lançamentos de um dado, em média, até sair 6 três vezes SEGUIDAS?
// A matemática diz 258 (6 + 36 + 216). Confira por simulação: repita o
// experimento 10 000 vezes (com srand(2026)) e mostre a média de lançamentos
// e o pior caso:
//
//   Média: 257.2 lançamentos
//   Pior caso: 2860 lançamentos
//
// Dicas:
// 1. Laço de fora: os 10 000 experimentos. Laço de dentro: lança enquanto
//    seguidos < 3.
// 2. Tirou 6: seguidos++. Qualquer outra face: seguidos = 0. Os contadores
//    do experimento (seguidos e lancamentos) recomeçam a cada volta de fora.
// 3. Resposta esperada: média perto de 258 (na glibc com semente 2026,
//    257.2, e pior caso 2860). Use long para a soma de todos os lançamentos.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
