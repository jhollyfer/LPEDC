// Lista · Módulo 07 · Memória dinâmica
// Exercício P0708 · ★☆☆ · A transposta numa matriz nova
//
// Escreva int **transposta(int **m, int l, int c), que devolve uma matriz
// NOVA no heap, c x l, com t[j][i] = m[i][j]. A original continua inteira.
// Use funções criar(l, c) e liberar(m, l), como no texto do assunto 0056. No
// main, crie a matriz 2x3 de horas extras abaixo (linhas: Ana e Davi; colunas:
// semana 1 a 3), monte a transposta, mostre as duas e libere as duas:
//
//   2 5 1
//   4 0 3
//
//   Saída esperada:
//   Original (2x3):
//   2 5 1
//   4 0 3
//   Transposta (3x2):
//   2 4
//   5 0
//   1 3
//
// Dicas:
// 1. A transposta tem c linhas de l colunas: int **t = criar(c, l);
// 2. Na hora de liberar, cada matriz é liberada com o SEU número de
//    linhas: liberar(m, 2) e liberar(t, 3).
// 3. Se criar devolver NULL, libere o que já existe antes de sair.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
