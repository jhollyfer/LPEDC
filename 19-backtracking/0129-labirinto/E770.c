// 0129 · Labirinto
// Exercício E770 · ★☆☆
//
// O ratinho do laboratório entra pelo canto (0, 0) de cada labirinto e o
// queijo está no canto oposto, marcado com Q. Escreva do zero a função
//
//   bool chega(int l, int c)
//
// que diz se o rato alcança o queijo (andando para cima, baixo, esquerda e
// direita, sem atravessar paredes #), e use-a nos dois labirintos do
// programa. Copie o labirinto da vez para a matriz global lab antes de
// chamar a função (strcpy em cada linha).
//
//   Saída esperada:
//   labirinto 1: o rato chega ao queijo
//   labirinto 2: sem caminho até o queijo
//
// Dicas:
// 1. É a função anda do texto, sem a marca de beco: aqui não interessa o
//    caminho, só a resposta. Marque as casas visitadas com qualquer letra.
// 2. Recuse fora do mapa, parede e casa já visitada; aceite o Q.
// 3. No labirinto 2, uma parede fecha o caminho na coluna 3: confira no
//    papel antes de rodar.
// 4. Resposta esperada: as 2 linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define L 5
#define C 5

char lab[L][C + 1];

const char *lab1[L] = {
    "..#..",
    "#.#.#",
    "..#..",
    ".#...",
    "...#Q",
};
const char *lab2[L] = {
    "...#.",
    "#..#.",
    ".#.#.",
    "...#.",
    ".#.#Q",
};

int main(void) {

    return 0;
}
