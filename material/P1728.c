// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1728 · ★★★ · Fabrique o pior caso do merge sort
//
// O merge sort intercala com no máximo n - 1 comparações; o pior caso total,
// para n potência de 2, é n lg n - n + 1. Que entrada provoca isso? Uma
// intercalação faz n - 1 comparações quando as duas metades se alternam até
// o fim: o maior e o segundo maior ficam em metades diferentes, e assim por
// diante. Dá para FABRICAR a entrada desfazendo o merge sort:
//
//   pior(v[0..n-1] ordenado): os elementos das posições pares vão para a
//   metade esquerda, os das ímpares para a direita, e cada metade é
//   arrumada recursivamente do mesmo jeito.
//
// Escreva pior() e um merge sort que conte comparações. Para n = 8, 16 e
// 1024, mostre as comparações com a entrada já ordenada, com a fabricada, a
// fórmula n lg n - n + 1 e o limite inferior ⌈lg n!⌉ de qualquer ordenação
// por comparação. Mostre também a entrada fabricada para n = 8 (com as notas
// 1 a 8 de uma prova).
//
//   Saída esperada:
//      n  ordenada  fabricada  n lg n - n + 1  teto(lg n!)
//      8        12         17              17           16
//     16        32         49              49           45
//   1024      5120       9217            9217         8770
//   Entrada fabricada (n = 8): 1 5 3 7 2 6 4 8
//
// Dicas:
// 1. pior(v, n): copie os de índice par para aux[0..n/2-1] e os de índice
//    ímpar para aux[n/2..n-1], chame pior nas duas metades de aux e copie de
//    volta. Com n == 1, nada a fazer.
// 2. Na entrada ordenada, cada intercalação esgota a metade esquerda primeiro:
//    n/2 comparações por nível, (n/2) lg n no total.
// 3. ⌈lg n!⌉ sai de somar log2(i) para i de 2 a n (com double) e arredondar
//    para cima.
// 4. Resposta esperada: para n = 8, a entrada 1 5 3 7 2 6 4 8 dá 17
//    comparações (fórmula 17, limite 16); para n = 1024, 9217 contra o limite
//    8770.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAX 1024

int main(void) {

    return 0;
}
