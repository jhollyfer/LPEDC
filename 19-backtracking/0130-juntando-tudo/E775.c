// 0130 · Juntando tudo
// Exercício E775 · ★☆☆
//
// Antes de confiar num resolvedor, você precisa de um conferente. Escreva a
// função
//
//   bool confere(int g[9][9], char *onde, int *qual)
//
// que diz se uma grade COMPLETA de sudoku está certa. Se não estiver, ela
// guarda em *onde o tipo do primeiro problema ('L' linha, 'C' coluna, 'X'
// caixa) e em *qual o número dele. Confira nessa ordem: todas as linhas,
// depois todas as colunas, depois todas as caixas. Teste com as duas grades
// do programa: a primeira é a solução do texto; na segunda, alguém trocou
// dois números de lugar.
//
//   Saída esperada:
//   grade 1: certa
//   grade 2: errada (coluna 0)
//
// Dicas:
// 1. Para cada linha, use um vetor bool visto[10] zerado: se um dígito já
//    foi visto, a linha está errada.
// 2. A caixa b (0 a 8) começa na linha (b / 3) * 3 e na coluna (b % 3) * 3.
//    A i-ésima casa dela (i de 0 a 8) está em (+ i / 3, + i % 3).
// 3. Na grade 2, a troca foi dentro da linha 4: as linhas continuam certas,
//    por isso o primeiro problema aparece nas colunas.
// 4. Resposta esperada: as 2 linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int grade1[9][9] = {
    {2, 7, 3, 6, 8, 5, 1, 4, 9}, {6, 8, 5, 9, 4, 1, 3, 7, 2}, {9, 4, 1, 2, 7, 3, 5, 8, 6},
    {5, 2, 8, 1, 6, 4, 7, 9, 3}, {3, 9, 7, 5, 2, 8, 4, 6, 1}, {1, 6, 4, 3, 9, 7, 8, 2, 5},
    {8, 3, 2, 4, 5, 6, 9, 1, 7}, {4, 5, 6, 7, 1, 9, 2, 3, 8}, {7, 1, 9, 8, 3, 2, 6, 5, 4},
};
int grade2[9][9] = {
    {2, 7, 3, 6, 8, 5, 1, 4, 9}, {6, 8, 5, 9, 4, 1, 3, 7, 2}, {9, 4, 1, 2, 7, 3, 5, 8, 6},
    {5, 2, 8, 1, 6, 4, 7, 9, 3}, {9, 3, 7, 5, 2, 8, 4, 6, 1}, {1, 6, 4, 3, 9, 7, 8, 2, 5},
    {8, 3, 2, 4, 5, 6, 9, 1, 7}, {4, 5, 6, 7, 1, 9, 2, 3, 8}, {7, 1, 9, 8, 3, 2, 6, 5, 4},
};

int main(void) {

    return 0;
}
