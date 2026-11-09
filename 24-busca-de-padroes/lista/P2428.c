// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2428 · ★★★ · O logotipo na tela
//
// O Rabin-Karp também procura em 2D. A tela tem 6 linhas de 12 pixels
// ('#' aceso, '.' apagado) e o logotipo é um bloco de 2 linhas por 3
// colunas:
//
//   #.#
//   ###
//
// Escreva do zero (base 256, Q = 1000003):
// - o hash de cada linha do logotipo;
// - para cada linha da tela, o hash ROLANTE de cada trecho de 3 pixels,
//   guardado em janela[i][j];
// - um bloco com canto em (i, j) só é conferido pixel a pixel quando
//   janela[i + r][j] bate com o hash da linha r do logotipo, para r = 0 e 1.
// Mostre onde o logotipo aparece e quantos blocos foram conferidos.
//
//   Saída esperada:
//   logotipo na linha 1, coluna 6
//   logotipo na linha 4, coluna 7
//   Total: 2; blocos conferidos letra a letra: 2
//
// Dicas:
// 1. As janelas da tela custam O(L · C) para montar; depois cada canto
//    custa só 2 comparações de números.
// 2. O índice da janela é o canto esquerdo: j vai de 0 até C - 3.
// 3. Resposta esperada: linha 1, coluna 6 e linha 4, coluna 7; os
//    "#.#" das linhas 0 e 3 não contam porque embaixo deles não há "###".
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define L 6
#define C 12

const char *tela[L] = {"..#.#.......", ".###..#.#...", "......###...",
                       "..#.#.......", ".###...#.#..", ".......###.."};
const char *logo[2] = {"#.#", "###"};

int main(void) {
    for (int i = 0; i < L; i++) printf("%s\n", tela[i]);
    printf("%s\n", logo[0]);
    return 0;
}
