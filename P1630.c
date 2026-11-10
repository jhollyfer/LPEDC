// Lista · Módulo 16 · Grafos
// Exercício P1630 · ★★★ · Fuga do incêndio no galpão
//
// Um galpão em grade pegou fogo. # é parede, F é onde há fogo agora, P é a
// pessoa e . é passagem. A cada minuto, o fogo se espalha para as casas
// vizinhas (cima, baixo, esquerda, direita) e a pessoa anda uma casa. Ela
// escapa ao chegar a uma casa da BORDA da grade e sair por ela, e só pode
// entrar numa casa se chegar ANTES do fogo (chegar no mesmo minuto não vale).
//
// São duas BFS em grade:
//
// 1. uma BFS com VÁRIAS origens (todas as casas F entram na fila no tempo 0)
// calcula fogo[casa], o minuto em que o fogo chega;
// 2. uma BFS a partir de P anda só por casas com passo < fogo[casa].
//
// Escreva int fuga(char mapa[][C + 1]), que devolve o número de minutos até
// sair (passos até a casa da borda + 1 para sair), ou -1. Mostre também o
// mapa do fogo (minuto em que chega em cada casa, # nas paredes) para o
// primeiro galpão. Rode nos dois galpões do esqueleto.
//
//   Saída esperada:
//   Fogo no galpão 1 (minuto em que chega):
//     #  #  #  3  #  #  #  #  #
//     #  0  1  2  #  8  9 10  #
//     #  1  #  3  #  7  # 11  #
//     #  2  3  4  5  6  # 12 13
//     #  #  #  #  #  #  #  #  #
//   Galpão 1: 9 minutos
//   Galpão 2: -1
//
// Dicas:
// 1. Casas que o fogo nunca alcança ficam com fogo = INT_MAX (ou um número
//    grande): a pessoa sempre pode entrar nelas.
// 2. Na BFS da pessoa, a casa v só entra se passo[u] + 1 < fogo[v]. A
//    própria P está no tempo 0 e o fogo ainda não está nela.
// 3. Ao tirar da fila uma casa na borda (l == 0, l == L - 1, c == 0 ou
//    c == C - 1), a resposta é passo + 1.
// 4. Resposta esperada: no galpão 1, a saída de cima (5 minutos sem fogo)
//    está fechada pelo fogo, e a pessoa sai pela direita em 9 minutos; no
//    galpão 2, o fogo fecha a única saída e a resposta é -1.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdio.h>

#define L 5
#define C 9

char galpao1[L][C + 1] = {
    "###.#####",
    "#F..#...#",
    "#.#.#.#.#",
    "#...P.#..",
    "#########",
};
char galpao2[L][C + 1] = {
    "#########",
    "#P.....F#",
    "#.#####.#",
    "#......F.",
    "#########",
};

int main(void) {

    return 0;
}
