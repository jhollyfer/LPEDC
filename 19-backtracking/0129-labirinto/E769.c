// 0129 · Labirinto
// Exercício E769 · ★☆☆
//
// No mapa do sítio, # é cerca e . é grama. A vaca está na casa (2, 3) e
// anda livre pela grama, mas não pula cerca. O sitiante quer saber quantas
// casas de grama ela alcança (a área do pasto dela). Escreva int pasto(int
// l, int c), um flood fill recursivo nas quatro direções (direita, baixo,
// esquerda, cima) que marca com 'v' cada casa alcançada e devolve quantas
// são. Mostre o mapa e a área.
//
//   Saída esperada:
//   ##########
//   #vvvv#...#
//   #vvvv#...#
//   #vv###...#
//   #vv#.....#
//   ##########
//   a vaca alcança 12 casas
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define L 6
#define C 10

char mapa[L][C + 1] = {
    "##########",
    "#....#...#",
    "#....#...#",
    "#..###...#",
    "#..#.....#",
    "##########",
};

int main(void) {

    return 0;
}
