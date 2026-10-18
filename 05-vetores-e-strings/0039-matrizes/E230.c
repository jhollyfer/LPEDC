// 0039 · Matrizes
// Exercício E230 · ★☆☆
//
// Declare as duas matrizes abaixo e mostre-as inteiras, em forma de grade,
// para ver onde o compilador pôs os zeros. O número de linhas de b não está
// escrito em lugar nenhum: calcule com sizeof e use no laço. No fim, mostre
// quantos bytes a ocupa e quantos ocupa uma linha dela.
//
//   int a[2][3] = {{1}, {4, 5}};
//   int b[][2] = {{1, 2}, {3, 4}, {5}};
//
//   Saída esperada:
//   a (2x3):
//   1 0 0
//   4 5 0
//   b (3 linhas):
//   1 2
//   3 4
//   5 0
//   a: 24 bytes, uma linha: 12 bytes
//
// Dicas:
// 1. Com chaves internas, cada chave é uma linha; o que falta vira 0.
// 2. sizeof(b) / sizeof(b[0]) é o número de linhas: o tamanho da matriz
//    dividido pelo de uma linha. Guarde num int.
// 3. sizeof(a[0]) é o tamanho de uma linha de a. Mostre com %zu.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
