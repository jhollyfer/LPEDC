// 0129 · Labirinto
// Exercício E772 · ★★☆
//
// O robô aspirador precisa ir da base (S) até a tomada (F), e o programa
// abaixo já acha um caminho e desenha a planta com ele marcado. Mas o robô não
// entende desenho: ele precisa da lista de casas, na ordem. Estenda o
// programa para guardar o caminho enquanto a busca anda e mostrar as
// coordenadas, da base até a tomada, e o número de passos.
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
// Escreva sua resposta abaixo (estenda o programa):

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

bool anda(int l, int c) {
    if (l < 0 || l >= L || c < 0 || c >= C) {
        return false;
    }
    if (planta[l][c] == 'F') {
        return true;
    }
    if (planta[l][c] != '.' && planta[l][c] != 'S') {
        return false;
    }
    planta[l][c] = '*';
    if (anda(l, c + 1) || anda(l + 1, c) || anda(l, c - 1) || anda(l - 1, c)) {
        return true;
    }
    planta[l][c] = 'x';
    return false;
}

int main(void) {
    if (anda(0, 0)) {
        for (int l = 0; l < L; l++) {
            for (int c = 0; c < C; c++) {
                printf(c == 0 ? "%c" : " %c", planta[l][c]);
            }
            printf("\n");
        }
    }
    return 0;
}
