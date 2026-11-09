// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1920 · ★★☆ · O rodízio dos quatro feirantes
//
// Quatro feirantes (1, 2, 3 e 4) dividem quatro barracas e quatro dias da
// semana. A escala é uma grade 4 × 4: a linha é o dia, a coluna é a
// barraca e o número é o feirante. Cada feirante aparece uma vez em cada
// dia e uma vez em cada barraca. Isso é um QUADRADO LATINO, o sudoku sem os
// blocos. Escreva do zero um backtracking que preenche a grade casa a casa
// e conta quantas escalas existem. Mostre a primeira, o total e quantas
// têm o primeiro dia na ordem 1 2 3 4.
//
//   Saída esperada:
//   1 2 3 4
//   2 1 4 3
//   3 4 1 2
//   4 3 2 1
//   Escalas: 576
//   Com o primeiro dia 1 2 3 4: 24
//
// Dicas:
// 1. Casa k vai de 0 a 15: lin = k / 4, col = k % 4. Um número pode entrar
//    se não está na linha nem na coluna; dois vetores booleanos por linha e
//    por coluna deixam o teste em O(1).
// 2. Ao fechar a grade, confira se a linha 0 é 1 2 3 4 para o segundo
//    contador.
// 3. Resposta esperada: 576 escalas e 24 com o primeiro dia 1 2 3 4
//    (576 / 4! = 24: qualquer escala vira uma dessas trocando os nomes).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
