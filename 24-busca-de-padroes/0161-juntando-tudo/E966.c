// 0161 · Juntando tudo
// Exercício E966 · ★★★
//
// O narrador falou o jogo inteiro. Conte quantas vezes cada palavra da lista
// {"gol", "bola", "juiz", "falta", "trave"} aparece na narração com o
// pb_horspool, guarde num vetor de struct {palavra, vezes} e ordene com qsort:
// mais vezes primeiro; empate em ordem alfabética. Mostre o ranking e o total
// de comparações de letra das cinco buscas:
//
//   "gol! a bola bateu na trave, o juiz deu falta, a bola voltou e foi gol
//    de novo; falta na entrada da area, bola na trave e gol"
//
//   Saída esperada:
//   1º bola  3
//   2º gol   3
//   3º falta 2
//   4º trave 2
//   5º juiz  1
//   (218 comparações de letra no total)
//
// Dicas:
// 1. typedef struct { const char *palavra; int vezes; } Contagem;
// 2. A compara recebe const void * (assunto 0050). Para "mais vezes
//    primeiro" sem o risco de overflow do b - a, use
//    (y->vezes > x->vezes) - (y->vezes < x->vezes); no empate, strcmp.
// 3. O mesmo long comp pode acumular as cinco buscas: as funções somam.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "padroes.h"

int main(void) {

    return 0;
}
