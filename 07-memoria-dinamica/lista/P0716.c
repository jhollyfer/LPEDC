// Lista · Módulo 07 · Memória dinâmica
// Exercício P0716 · ★★☆ · Recortar a imagem
//
// Uma imagem em preto e branco está num vetor de strings, uma por linha
// ('#' é pixel aceso):
//
//   const char *img[6] = {"..........",
//                         "..####....",
//                         ".#....#...",
//                         ".#.##.#...",
//                         "..####....",
//                         ".........."};
//
// Escreva char **recortar(const char **img, int l0, int c0, int alt,
// int larg), que devolve uma imagem NOVA no heap com alt linhas, cada uma uma
// string de larg caracteres (+ '\0'), copiada a partir da linha l0, coluna
// c0. Escreva também void liberar(char **m, int alt). Recorte o desenho
// (linhas 1 a 4, colunas 1 a 6) e, do recorte, só o miolo 2x4 (linhas 1 e 2,
// colunas 1 a 4 do recorte):
//
//   Saída esperada:
//   Recorte 4x6:
//     .####.
//     #....#
//     #.##.#
//     .####.
//   Miolo 2x4:
//     ....
//     .##.
//
// Dicas:
// 1. m = malloc(alt * sizeof *m); m[i] = malloc(larg + 1); e copie
//    img[l0 + i][c0 + j] para m[i][j]. Feche cada linha com m[i][larg] = '\0'.
// 2. Para recortar o recorte, passe (const char **) recorte: as linhas dele
//    também são strings.
// 3. Cada recorte é liberado com o seu número de linhas.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char *img[6] = {"..........",
                          "..####....",
                          ".#....#...",
                          ".#.##.#...",
                          "..####....",
                          ".........."};
    (void) img; // apague esta linha quando escrever

    return 0;
}
