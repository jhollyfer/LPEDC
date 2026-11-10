// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2725 · ★★★ · Girar a foto 90 graus
//
// Uma foto em tons de cinza é uma matriz de pixels. Escreva, com parâmetros
// VLA:
//
//   void girar(int l, int c, int a[l][c], int r[c][l])  // 90° no sentido horário
//   void mostrar(int l, int c, int m[l][c])
//   bool iguais(int l, int c, int a[l][c], int b[l][c])
//
// Gire a foto 2 x 3 abaixo e mostre o resultado. Depois, com uma 3 x 3
// preenchida de 1 a 9, gire quatro vezes seguidas e confira que voltou à
// original.
//
//   1 2 3
//   4 5 6
//
//   Saída esperada:
//   girada (3 x 2):
//     4  1
//     5  2
//     6  3
//   4 giros na 3 x 3 voltam ao original? sim
//
// Dicas:
// 1. Girando no sentido horário, a linha i da original vira a coluna
//    l - 1 - i da girada: r[j][l - 1 - i] = a[i][j].
// 2. Para girar várias vezes, alterne entre duas matrizes 3 x 3 (ou copie
//    de volta depois de cada giro).
// 3. VLA não aceita = {...}: preencha a 2 x 3 com a[i][j] = i * c + j + 1.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
