// 0130 · Juntando tudo
// Exercício E777 · ★★☆
//
// O caderno infantil de passatempos traz o sudoku 6 × 6: dígitos de 1 a 6,
// sem repetir na linha, na coluna e em cada bloco de 2 linhas por 3 colunas.
// Escreva um resolvedor para ele (pode adaptar o do texto) e resolva o jogo
// abaixo, contando as chamadas da função recursiva.
//
//   ..2..3
//   1..2..
//   .1....
//   6..3..
//   24.6..
//   .6.5..
//
//   Saída esperada:
//   4 5 2 | 1 6 3
//   1 3 6 | 2 5 4
//   ------+------
//   5 1 3 | 4 2 6
//   6 2 4 | 3 1 5
//   ------+------
//   2 4 5 | 6 3 1
//   3 6 1 | 5 4 2
//   73 chamadas
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    const char *jogo[6] = {"..2..3", "1..2..", ".1....", "6..3..", "24.6..", ".6.5.."};
    (void)jogo; // apague esta linha quando usar o vetor

    return 0;
}
