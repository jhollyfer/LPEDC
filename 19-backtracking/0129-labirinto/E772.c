// 0129 · Labirinto
// Exercício E772 · ★★☆
//
// O robô aspirador precisa ir da base (S) até a tomada (F) na planta abaixo.
// Escreva um backtracking que ande pelas casas '.', tentando os vizinhos na
// ordem direita, baixo, esquerda, cima. Marque o caminho com '*' (e as casas
// sem saída com 'x') e guarde as coordenadas enquanto anda. Mostre a planta
// com o caminho, com um espaço entre as casas, depois a lista de casas, da
// base até a tomada, e o número de passos.
//
//   Saída esperada:
//   * * # . . .
//   . * # . # .
//   . * * * # .
//   # # # * * *
//   . . . . # F
//   caminho: (0,0) (0,1) (1,1) (2,1) (2,2) (2,3) (3,3) (3,4) (3,5) (4,5)
//   9 passos
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define L 5
#define C 6

char planta[L][C + 1] = {
    "S.#...",
    "..#.#.",
    "....#.",
    "###...",
    "....#F",
};

int main(void) {

    return 0;
}
