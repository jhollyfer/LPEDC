// 0129 · Labirinto
// Exercício E769 · ★☆☆
//
// No mapa do sítio, # é cerca e . é grama. A vaca está na casa (2, 3) e
// anda livre pela grama, mas não pula cerca. O sitiante quer saber quantas
// casas de grama ela alcança (a área do pasto dela). A função pasto abaixo
// faz um flood fill, mas falta a linha que soma as casas: complete o return
// com as quatro chamadas recursivas.
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
// Escreva sua resposta abaixo (complete o código):

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

int pasto(int l, int c) {
    if (l < 0 || l >= L || c < 0 || c >= C || mapa[l][c] != '.') {
        return 0;
    }
    mapa[l][c] = 'v';
    return 1; // complete: some as casas que os quatro vizinhos alcançam
}

int main(void) {
    int area = pasto(2, 3);
    for (int l = 0; l < L; l++) {
        printf("%s\n", mapa[l]);
    }
    printf("a vaca alcança %d casas\n", area);
    return 0;
}
