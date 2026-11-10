// 0183 · Hamiltoniano
// Exercício E1093 · ★☆☆
//
// Achar um ciclo hamiltoniano é difícil; conferir um é fácil. O mapa das
// agências tem 6 vértices (0 a 5) e as vias 0-1, 0-2, 0-4, 1-2, 1-3, 2-3,
// 3-4, 3-5 e 4-5, guardadas na matriz via. Escreva
// bool eh_ciclo_hamiltoniano(const int rota[], int n), que recebe uma rota
// (sem repetir o primeiro no fim) e responde se ela é um ciclo
// hamiltoniano: tem os V vértices, nenhum repetido, e cada vizinho da rota
// (inclusive o último com o primeiro) tem via. Teste as quatro rotas:
//
//   rota 1: 0 1 2 3 5 4    rota 2: 0 1 2 3 4 5
//   rota 3: 0 2 1 3 5 4    rota 4: 0 1 3 5 4 1
//
//   Saída esperada:
//   Rota 1: válida
//   Rota 2: inválida
//   Rota 3: válida
//   Rota 4: inválida
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define V 6

int via[V][V];

int main(void) {

    return 0;
}
