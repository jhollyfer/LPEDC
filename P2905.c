// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2905 · ★☆☆ · Conferindo a rota do ônibus circular
//
// O ônibus circular passa por seis pontos (0 a 5), numa cidade de ruas de
// mão única. As ruas dirigidas são:
//
//   0->1, 1->2, 2->3, 3->4, 4->5, 5->0, 1->4, 3->1, 4->2, 2->0
//
// A empresa recebeu quatro propostas de rota (começando no ponto 0; a volta
// ao 0 fica subentendida) e quer saber quais são ciclos hamiltonianos
// DIRIGIDOS. Escreva o verificador bool valida(const int r[], int n), que
// mostra "ok" ou o primeiro problema: "falta ponto", "repete o ponto X" ou
// "não há rua X->Y" (inclusive na volta).
//
//   A: 0 1 2 3 4 5     B: 0 1 4 2 3 1     C: 0 1 4 5 2 3     D: 0 1 4 2 3
//
//   Saída esperada:
//   A: ok
//   B: repete o ponto 1
//   C: não há rua 5->2
//   D: falta ponto
//
// Dicas:
// 1. Primeiro confira o tamanho (n == 6), depois as repetições com um vetor
//    bool visto[], depois as ruas, inclusive a de r[n - 1] para r[0].
// 2. Num grafo dirigido, rua[x][y] = 1 não implica rua[y][x] = 1.
// 3. Resposta esperada: a saída acima. O verificador custa O(n): é por isso que
//    o problema do ciclo hamiltoniano está em NP.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
