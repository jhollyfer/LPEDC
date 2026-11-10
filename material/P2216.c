// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2216 · ★★☆ · As ilhas que surgem na vazante
//
// Na vazante do rio, bancos de areia vão aparecendo numa área mapeada como
// uma grade 4 × 5. Cada dia surge uma casa de areia nova, nesta ordem
// (linha, coluna):
//
//   (0,0) (0,1) (2,2) (1,4) (2,1) (1,1) (3,4) (2,4) (0,3) (1,3)
//
// Duas casas de areia vizinhas na horizontal ou na vertical são a mesma
// ilha. Depois de cada dia, quantas ilhas há? Escreva do zero: cada casa
// (l, c) é o elemento l * 5 + c de um union-find; ao surgir uma casa, conte
// +1 ilha e una com cada vizinha que já é areia (cada união de raízes
// diferentes tira 1 ilha).
//
//   Saída esperada:
//   Dia  1, areia em (0,0): 1 ilha(s)
//   Dia  2, areia em (0,1): 1 ilha(s)
//   Dia  3, areia em (2,2): 2 ilha(s)
//   Dia  4, areia em (1,4): 3 ilha(s)
//   Dia  5, areia em (2,1): 3 ilha(s)
//   Dia  6, areia em (1,1): 2 ilha(s)
//   Dia  7, areia em (3,4): 3 ilha(s)
//   Dia  8, areia em (2,4): 2 ilha(s)
//   Dia  9, areia em (0,3): 3 ilha(s)
//   Dia 10, areia em (1,3): 2 ilha(s)
//
// Dicas:
// 1. Um vetor areia[20] marca quais casas já surgiram; só una com vizinhas
//    marcadas.
// 2. Faça une devolver 1 quando juntou duas raízes diferentes e 0 quando
//    já estavam juntas.
// 3. Resposta esperada: a contagem da saída, terminando com 2 ilhas.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
