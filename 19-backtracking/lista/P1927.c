// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1927 · ★★★ · Futoshiki 4 × 4
//
// O futoshiki é um quadrado latino 4 × 4 (1 a 4 sem repetir na linha nem
// na coluna) com sinais de desigualdade entre algumas casas vizinhas, e
// nenhum número dado. O jogo de hoje tem 6 sinais (linha, coluna):
//
//   (0,1) < (0,0)    (2,2) < (2,3)    (1,2) < (0,2)
//   (1,3) < (0,3)    (3,2) < (2,2)    (2,3) < (3,3)
//
// Escreva do zero o resolvedor: preencha casa a casa, como no sudoku, e,
// ao pôr um número, confira só as desigualdades em que as DUAS casas já
// estão preenchidas (as de casas anteriores na ordem de preenchimento).
// Conte as soluções (um bom jogo tem uma só) e mostre a grade.
//
//   Saída esperada:
//   Soluções: 1
//   3 1 4 2
//   4 2 3 1
//   1 4 2 3
//   2 3 1 4
//
// Dicas:
// 1. Guarde os sinais num vetor de structs { la, ca, lb, cb }: a casa A é
//    menor que a casa B. Casa vazia vale 0.
// 2. ok_sinais(): para cada sinal com as duas casas diferentes de 0, a
//    casa A tem que ser menor. Chame depois de pôr o número.
// 3. Resposta esperada: 1 solução, a grade de cima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
