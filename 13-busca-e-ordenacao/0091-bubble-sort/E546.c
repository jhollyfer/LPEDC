// 0091 · Bubble sort
// Exercício E546 · ★★★
//
// Uma INVERSÃO é um par de posições i < j com v[i] > v[j]. Escreva:
//
//   int inversoes(const int v[], int n)      conta os pares, com dois laços
//   int trocas_bubble(int v[], int n)        ordena e devolve quantas trocas fez
//
// Teste com 42 17 35 8 23, com 6 5 4 3 2 1 e com 3 1 2 (conte as inversões
// ANTES de ordenar). Depois de ordenar, chame inversoes de novo e mostre
// quantas sobraram.
//
//   Saída esperada:
//   n = 5: 7 inversões, 7 trocas, 0 depois
//   n = 6: 15 inversões, 15 trocas, 0 depois
//   n = 3: 2 inversões, 2 trocas, 0 depois
//
// Dicas:
// 1. Na inversoes, o j começa em i + 1.
// 2. O que acontece com as inversões quando você troca dois VIZINHOS a > b?
//    E com os outros pares?
// 3. No vetor invertido, todo par é uma inversão: n(n - 1)/2.
// 4. Resposta esperada: a saída acima. Cada troca de vizinhos desfaz
//    exatamente uma inversão e não cria nenhuma; o vetor ordenado tem zero.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
