// 0042 · Lendo strings
// Exercício E252 · ★★★
//
// O programa abaixo lê com fgets num vetor de só 6 bytes, num laço, até a
// entrada acabar. Uma linha longa chega em pedaços, e cada pedaço parece uma
// linha nova. Sem aumentar o vetor s, mude o programa para que ele:
//
//   1. mostre cada pedaço numerado, entre colchetes, com o '\n' (quando vier)
//      escrito como \n, sem quebrar a linha da tela;
//   2. perceba quando um pedaço fecha uma linha (termina em '\n') e mostre o
//      número da linha e quantas letras ela teve, somando os pedaços;
//   3. no fim, mostre quantas leituras e quantas linhas de verdade houve.
//
// Rode com printf 'abacaxi\nuva\n' | ~/LPEDC/rodar seguido do caminho deste
// arquivo.
//
//   Saída esperada:
//   pedaço 1: [abaca]
//   pedaço 2: [xi\n] fim da linha 1 (7 letras)
//   pedaço 3: [uva\n] fim da linha 2 (3 letras)
//   3 leituras, 2 linhas
//
// Escreva sua resposta abaixo (mude o programa):

#include <stdio.h>
#include <string.h>

int main(void) {
    char s[6];
    int leituras = 0;

    while (fgets(s, sizeof(s), stdin) != NULL) {
        printf("[%s]", s);
        leituras++;
    }
    printf("\n%d leituras\n", leituras);
    return 0;
}
