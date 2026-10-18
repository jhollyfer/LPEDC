// 0138 · Memoização
// Exercício E823 · ★☆☆
//
// Na escadaria da igreja da cidade, os adolescentes sobem de 1, de 2 ou de 3
// degraus por vez. São 10 degraus. Escreva um programa que calcula, de baixo
// para cima, quantos jeitos existem de subir 0, 1, 2, ..., 10 degraus, num
// vetor t[], e mostre a tabela inteira e a resposta.
//
//   Saída esperada:
//   t: 1 1 2 4 7 13 24 44 81 149 274
//   Jeitos de subir 10 degraus: 274
//
// Dicas:
// 1. O último passo foi de 1, de 2 ou de 3 degraus: t[i] = t[i - 1] +
//    t[i - 2] + t[i - 3].
// 2. Os casos base são t[0] = 1, t[1] = 1 e t[2] = 2 (11 ou 2).
// 3. Comece o laço em i = 3: assim nenhum índice fica negativo.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
