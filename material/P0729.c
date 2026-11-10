// Lista · Módulo 07 · Memória dinâmica
// Exercício P0729 · ★★★ · Quantas ilhas tem o mapa do rio
//
// Num mapa de satélite do Anavilhanas, '#' é terra e '.' é água. Uma ILHA é
// um grupo de '#' ligados na horizontal ou na vertical (diagonal não liga).
// O mapa vem como um vetor de strings:
//
//   const char *mapa[6] = {"##....#...",
//                          "##...###..",
//                          "......#...",
//                          "..#.......",
//                          ".###..##.#",
//                          "..#...##.#"};
//
// Conte as ilhas e o tamanho de cada uma. Use uma matriz dinâmica de bool
// visitado (alocada com calloc, já tudo false) e uma função recursiva
// int inundar(const char **mapa, bool **vis, int l, int c, int i, int j),
// que marca a casa (i, j) e as vizinhas de terra ainda não visitadas, e
// devolve quantas casas marcou:
//
//   Saída esperada:
//   Ilha 1: começa em (0, 0), 4 casas
//   Ilha 2: começa em (0, 6), 5 casas
//   Ilha 3: começa em (3, 2), 5 casas
//   Ilha 4: começa em (4, 6), 4 casas
//   Ilha 5: começa em (4, 9), 2 casas
//   Total: 5 ilhas
//
// Dicas:
// 1. Para cada casa de terra não visitada, chame inundar: é uma ilha nova.
// 2. Em inundar, o caso base é sair do mapa, achar água ou achar casa já
//    visitada: return 0. Senão, marque e devolva 1 + inundar das 4 vizinhas.
// 3. vis = malloc(l * sizeof *vis); vis[i] = calloc(c, sizeof *vis[i]);
// 4. A recursão usa a pilha: num mapa enorme, todo de terra, ela pode
//    estourar. Para mapas grandes, troca-se a recursão por uma pilha ou
//    fila no heap (módulos 12 e 16).
// 5. Resposta esperada: a saída acima (5 ilhas).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    const char *mapa[6] = {"##....#...",
                           "##...###..",
                           "......#...",
                           "..#.......",
                           ".###..##.#",
                           "..#...##.#"};
    (void) mapa; // apague esta linha quando escrever

    return 0;
}
