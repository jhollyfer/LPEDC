// Lista · Módulo 06 · Ponteiros
// Exercício P0627 · ★★★ · Multiplicar matrizes guardadas em fila
//
// Quando as dimensões mudam, é comum guardar a matriz num vetor simples:
// o elemento (i, j) de uma matriz com C colunas fica em v[i * C + j].
// Escreva
//
//   void multiplicar(const int *a, const int *b, int *c, int l, int m, int n);
//
// que calcula c = a x b, com a de l x m, b de m x n e c de l x n, todas
// nesse formato. Escreva também void mostrar(const int *v, int l, int c) e
// bool identidade(const int *v, int n). Calcule a x b para as matrizes
// abaixo e confira que a x I = a, com I a identidade 3x3:
//
//   int a[2 * 3] = {1, 2, 3,
//                   4, 5, 6};
//   int b[3 * 4] = {2, 0, 1, 3,
//                   1, 4, 0, 2,
//                   0, 1, 5, 1};
//
//   Saída esperada:
//   a x b (2x4):
//      4  11  16  10
//     13  26  34  28
//   id é identidade? sim
//   a x I == a? sim
//
// Dicas:
// 1. c[i * n + j] = soma de a[i * m + k] * b[k * n + j], para k de 0 a m - 1.
// 2. Monte a identidade 3x3 num int id[9] com id[i * 3 + j] = (i == j), e
//    teste-a com a sua função identidade antes de usar.
// 3. Para conferir a x I = a, compare as 6 posições do resultado com as de a.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int a[2 * 3] = {1, 2, 3,
                    4, 5, 6};
    int b[3 * 4] = {2, 0, 1, 3,
                    1, 4, 0, 2,
                    0, 1, 5, 1};
    (void) a, (void) b; // apague esta linha quando escrever

    return 0;
}
