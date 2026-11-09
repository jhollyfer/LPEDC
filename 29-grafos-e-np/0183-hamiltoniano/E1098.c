// 0183 · Hamiltoniano
// Exercício E1098 · ★★★
//
// O passeio do cavalo: num tabuleiro 5 x 5, o cavalo do xadrez sai do canto
// de cima à esquerda e precisa pisar em todas as 25 casas, uma vez cada. É
// um CAMINHO hamiltoniano no grafo em que cada casa é um vértice e cada
// salto em L é uma aresta, mas você não precisa montar a matriz: os
// vizinhos saem das oito jogadas. Escreva o backtracking
// bool passeio(int l, int c, int k), que põe o número k na casa (l, c) e
// tenta os saltos nesta ordem (linha, coluna):
//
//   (+2,+1) (+1,+2) (-1,+2) (-2,+1) (-2,-1) (-1,-2) (+1,-2) (+2,-1)
//
// Mostre o tabuleiro com a ordem das casas (%3d) e o número de chamadas.
//
//   Saída esperada:
//     1  6 15 10 21
//    14  9 20  5 16
//    19  2  7 22 11
//     8 13 24 17  4
//    25 18  3 12 23
//   Chamadas: 8840
//
// Dicas:
// 1. Guarde os saltos em dois vetores dl[8] e dc[8]. Uma casa é candidata
//    se está dentro do tabuleiro e ainda vale 0.
// 2. Marque casa[l][c] = k ao entrar; se k == 25, acabou. Se nenhum salto
//    der certo, volte casa[l][c] para 0 antes de devolver false.
// 3. Resposta esperada: a saída acima. Mude a ordem dos saltos e o número
//    de chamadas muda muito: no backtracking, a ordem das tentativas pesa.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
