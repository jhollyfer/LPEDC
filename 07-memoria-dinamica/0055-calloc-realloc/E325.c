// 0055 · calloc e realloc
// Exercício E325 · ★☆☆
//
// Num jogo de tabuleiro, o dado saiu assim em 12 jogadas:
// 3, 6, 1, 6, 2, 5, 6, 3, 4, 6, 1, 2. Use calloc para criar os contadores
// das faces (zerados) e mostre quantas vezes cada face saiu, com um # por
// vez.
//
//   Saída esperada:
//   1: 2 ##
//   2: 2 ##
//   3: 2 ##
//   4: 1 #
//   5: 1 #
//   6: 4 ####
//
// Dicas:
// 1. calloc(7, sizeof(int)) dá as posições 0 a 6; use 1 a 6 e ignore a 0.
// 2. contagem[jogadas[i]]++ conta a face da jogada i.
// 3. Resposta esperada: a saída acima. Troque calloc por malloc e rode
//    algumas vezes: os números mudam ou ficam errados, porque os contadores
//    começam com lixo.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
