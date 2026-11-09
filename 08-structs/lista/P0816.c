// Lista · Módulo 08 · Tipos compostos
// Exercício P0816 · ★★☆ · Batalha naval
//
// O tabuleiro de batalha naval é uma matriz 5x5 de structs:
//
//   typedef struct { bool navio; bool atingida; } Casa;
//
// Os navios ocupam as casas marcadas com '#' no mapa abaixo. Monte a matriz a
// partir do mapa (as linhas são strings), dispare os tiros da lista e mostre,
// para cada tiro, "água", "fogo!" ou "repetido". No fim, mostre o tabuleiro
// ('X' navio atingido, 'o' tiro na água, '#' navio intacto, '.' nada) e
// quantas casas de navio sobraram:
//
//   const char *mapa[5] = {".##..", ".....", "#...#", "#...#", "#...."};
//   int tiros[7][2] = {{0, 1}, {2, 2}, {0, 2}, {3, 0}, {0, 1}, {4, 4}, {2, 4}};
//
//   Saída esperada:
//   Tiro (0, 1): fogo!
//   Tiro (2, 2): água
//   Tiro (0, 2): fogo!
//   Tiro (3, 0): fogo!
//   Tiro (0, 1): repetido
//   Tiro (4, 4): água
//   Tiro (2, 4): fogo!
//   .XX..
//   .....
//   #.o.X
//   X...#
//   #...o
//   Sobram 3 casas de navio
//
// Dicas:
// 1. Casa t[5][5]; e t[i][j].navio = (mapa[i][j] == '#'); t[i][j].atingida =
//    false;
// 2. Escreva const char *atirar(Casa t[5][5], int l, int c), que devolve a
//    frase e marca a casa como atingida.
// 3. Um tiro numa casa já atingida é "repetido", tenha navio ou não.
// 4. Resposta esperada: a saída acima (sobram 3 casas de navio).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    const char *mapa[5] = {".##..", ".....", "#...#", "#...#", "#...."};
    int tiros[7][2] = {{0, 1}, {2, 2}, {0, 2}, {3, 0}, {0, 1}, {4, 4}, {2, 4}};
    (void) mapa, (void) tiros; // apague esta linha quando escrever

    return 0;
}
