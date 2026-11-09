// 0183 · Hamiltoniano
// Exercício E1096 · ★★☆
//
// Num quadrangular de turno único, cinco times jogaram todos contra todos
// (sem empate): Bahia, Ceará, Fortaleza, Remo e Sport (0 a 4). Resultados,
// vencedor primeiro:
//
//   Bahia x Ceará, Fortaleza x Bahia, Bahia x Sport, Remo x Bahia,
//   Ceará x Fortaleza, Ceará x Remo, Sport x Ceará, Fortaleza x Remo,
//   Fortaleza x Sport, Sport x Remo
//
// O jornalista quer pôr os cinco numa fila em que cada time venceu o
// seguinte. Isso é um CAMINHO hamiltoniano num grafo DIRIGIDO (seta do
// vencedor para o perdedor). Escreva o backtracking que acha a primeira
// fila, tentando os inícios e os vizinhos em ordem de índice.
//
//   Saída esperada:
//   Bahia > Ceará > Fortaleza > Sport > Remo
//
// Dicas:
// 1. venceu[a][b] = 1 só num sentido. O teste do vizinho é
//    venceu[ordem[pos - 1]][v].
// 2. É o caminho hamiltoniano do E1094, sem volta e com início variável.
// 3. Resposta esperada: a saída acima. Curiosidade: num torneio todos
//    contra todos essa fila SEMPRE existe (teorema de Rédei), mas achar o
//    ciclo hamiltoniano continua sendo trabalho de backtracking.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
