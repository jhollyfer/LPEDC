// Lista · Módulo 16 · Grafos
// Exercício P1622 · ★★★ · O cavalo do torneio de xadrez da escola
//
// No torneio de xadrez da escola, o desafio é levar o cavalo de a1 até h8 com
// o menor número de lances. Cada casa do tabuleiro 8 × 8 é um vértice, e o
// cavalo liga uma casa às (até) oito casas em "L" a partir dela: um grafo em
// grade sem matriz de adjacência, com os vizinhos calculados na hora.
//
// Escreva um programa que rode uma BFS a partir de a1 e mostre:
//
// - o tabuleiro com o número mínimo de lances até cada casa (linha 8 em
//   cima, coluna a à esquerda);
// - quantas casas ficam à distância máxima, e qual é essa distância;
// - um caminho mínimo de a1 até h8, com as casas na notação do xadrez.
//
// Use os saltos nesta ordem: (+1,+2), (+2,+1), (+2,-1), (+1,-2), (-1,-2),
// (-2,-1), (-2,+1), (-1,+2), com (coluna, linha).
//
//   Saída esperada:
//   8  5 4 5 4 5 4 5 6
//   7  4 3 4 3 4 5 4 5
//   6  3 4 3 4 3 4 5 4
//   5  2 3 2 3 4 3 4 5
//   4  3 2 3 2 3 4 3 4
//   3  2 1 4 3 2 3 4 5
//   2  3 4 1 2 3 4 3 4
//   1  0 3 2 3 2 3 4 5
//      a b c d e f g h
//   Distância máxima: 6 lances (1 casa)
//   a1 até h8 em 6 lances: a1 b3 c5 d7 f8 g6 h8
//
// Dicas:
// 1. Numere a casa como linha * 8 + coluna, com a1 = 0 e h8 = 63. Na
//    notação, a coluna vira 'a' + coluna e a linha vira '1' + linha.
// 2. Para imprimir com a linha 8 em cima, percorra as linhas de 7 até 0.
// 3. A BFS dá UM caminho mínimo, e qual ele é depende da ordem dos saltos;
//    o número de lances não depende.
// 4. Resposta esperada: h8 a 6 lances de a1; a distância máxima é 6.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
