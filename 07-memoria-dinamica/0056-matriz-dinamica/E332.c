// 0056 · Matriz dinâmica
// Exercício E332 · ★☆☆
//
// Uma matriz de 5 linhas e 8 colunas está guardada num bloco único:
// int *v = malloc(5 * 8 * sizeof *v); e o elemento (i, j) fica em
// v[i * 8 + j]. Responda de cabeça e depois confira com um programa que
// mostre as contas:
//
//   a) Em que índice de v fica o elemento (2, 3)?
//   b) E o (4, 7)? Por que ele é o último?
//   c) E o (0, 5)?
//   d) O índice 26 é qual (i, j)?
//
// Dicas:
// 1. Cada linha completa "pula" 8 posições.
// 2. Para voltar: i = k / 8 e j = k % 8.
// 3. Resposta esperada: a) 19; b) 39 = 5 * 8 - 1, a última das 40
//    posições; c) 5 (a linha 0 não pula nada); d) (3, 2), porque 26 / 8 = 3
//    e 26 % 8 = 2.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
