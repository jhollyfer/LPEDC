// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1921 · ★★★ · O cavalo com a regra de Warnsdorff
//
// No passeio do cavalo, o backtracking puro tenta os 8 saltos sempre na
// mesma ordem e, num tabuleiro 6 × 6, pode levar milhões de passos. Em
// 1823, Warnsdorff propôs uma regra simples: salte primeiro para a casa
// que tem MENOS saídas livres (a casa mais "apertada", que ficaria isolada
// depois). Escreva o passeio com essa regra, saindo do canto (0, 0) de um
// tabuleiro 6 × 6, mantendo o backtracking para o caso de a regra errar.
// Mostre o tabuleiro com a ordem de visita (1 a 36) e quantas vezes o
// programa precisou voltar atrás. Empate de saídas: vale a ordem dos
// saltos em dl[] e dc[].
//
//   Saída esperada:
//     1 10 19 26  7 12
//    20 27  8 11 18 25
//     9  2 31 24 13  6
//    36 21 28 15 32 17
//     3 30 23 34  5 14
//    22 35  4 29 16 33
//   Voltas: 0
//
// Dicas:
// 1. saidas(l, c) conta os saltos de (l, c) que caem dentro do tabuleiro
//    numa casa ainda com 0.
// 2. Em cada casa, monte um vetor com os candidatos (até 8) e o número de
//    saídas de cada um, ordene por saídas (insertion sort, estável, para
//    o empate seguir a ordem dos saltos) e tente nessa ordem.
// 3. Ao desfazer uma casa (tab = 0), some 1 em voltas.
// 4. Resposta esperada: o tabuleiro de cima e 0 voltas. A regra acerta de
//    primeira; sem ela (saltos sempre na ordem fixa), o mesmo programa
//    volta atrás 248133 vezes.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
