// Lista · Módulo 21 · Programação dinâmica
// Exercício P2118 · ★★☆ · O drone que gasta menos bateria
//
// Um drone de entregas cruza uma grade 5 × 5 de quarteirões do canto de
// cima à esquerda até o canto de baixo à direita, só para a direita (D) ou
// para baixo (B). Cada quarteirão gasta uma porcentagem da bateria (o
// vento muda), e # é prédio alto, onde ele não pode passar:
//
//   3 2 4 1 5
//   1 # 2 # 2
//   4 1 3 1 1
//   2 # 5 2 #
//   6 2 1 3 2
//
// Escreva do zero a PD do CAMINHO MÍNIMO EM GRADE: custo[l][c] = gasto do
// quarteirão + o menor entre custo[l - 1][c] e custo[l][c - 1]. Prédio vale
// infinito. Reconstrua o caminho como uma string de D e B.
//
//   Saída esperada:
//   Bateria gasta: 20%
//   Caminho: BBDDDBBD
//
// Dicas:
// 1. Guarde a grade como int, com -1 no prédio. O custo inclui o
//    quarteirão de saída e o de chegada.
// 2. Reconstrução: do fim, volte para o vizinho (de cima ou da esquerda)
//    com o menor custo, empilhando 'B' ou 'D'; inverta no fim.
// 3. Resposta esperada: 15% da bateria. Confira o caminho na saída.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
