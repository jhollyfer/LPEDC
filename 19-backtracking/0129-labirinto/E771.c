// 0129 · Labirinto
// Exercício E771 · ★★☆
//
// Na foto de satélite da fazenda, ~ é água e . é terra. Duas casas de água
// são do mesmo lago quando são vizinhas na horizontal ou na vertical
// (diagonal não conta). Escreva um programa que conte os lagos e mostre,
// para cada um, a primeira casa encontrada (varrendo linha por linha, da
// esquerda para a direita) e o tamanho.
//
//   Saída esperada:
//   lago 1: começa em (0, 0), tamanho 5
//   lago 2: começa em (1, 6), tamanho 4
//   lago 3: começa em (2, 10), tamanho 5
//   lago 4: começa em (3, 1), tamanho 4
//   lago 5: começa em (5, 6), tamanho 1
//   5 lagos
//
// Dicas:
// 1. Varra a matriz com dois laços. Achou um ~? É um lago novo: conte e
//    chame um flood fill a partir dali.
// 2. O flood fill troca cada ~ do lago por outro caractere (pode ser '.') e
//    devolve quantas casas trocou. Assim o mesmo lago não é contado de novo
//    quando a varredura passar pelas outras casas dele.
// 3. É a contagem de componentes conexos do assunto 0111, com a matriz no
//    lugar do grafo.
// 4. Resposta esperada: as 6 linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define L 6
#define C 12

char mapa[L][C + 1] = {
    "~~..........",
    "~~~...~~....",
    "......~~..~.",
    ".~.......~~~",
    ".~~~.....~..",
    "......~.....",
};

int main(void) {

    return 0;
}
