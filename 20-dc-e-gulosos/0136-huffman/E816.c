// 0136 · Código de Huffman
// Exercício E816 · ★★★
//
// Huffman sem heap. Quando as frequências já chegam ORDENADAS, dá para
// trocar o heap por duas filas: a das folhas (o vetor ordenado) e a dos nós
// internos (um vetor que você vai enchendo). O truque: os internos nascem em
// ordem crescente, então a fila deles também fica ordenada. A cada junção,
// o menor de todos está na frente de uma das duas filas: compare as duas
// frentes, tire o menor, e repita para o segundo. O custo cai para O(k).
//
// Faça isso para as frequências 1 1 2 3 5 8 13 21 (Fibonacci), mostrando
// cada junção e o total de bits (a soma de todas as junções).
//
//   Saída esperada:
//   junta  1 +  1 =  2
//   junta  2 +  2 =  4
//   junta  3 +  4 =  7
//   junta  5 +  7 = 12
//   junta  8 + 12 = 20
//   junta 13 + 20 = 33
//   junta 21 + 33 = 54
//   Total: 132 bits
//
// Dicas:
// 1. Índices: f para a próxima folha; ini e fim para a fila dos internos
//    (a fila é interno[ini..fim-1]).
// 2. Pegue da folha se ainda há folha e (a fila de internos está vazia ou
//    folha[f] <= interno[ini]); senão, pegue o interno. Faça isso duas vezes
//    por junção e enfileire a soma em interno[fim++].
// 3. Resposta esperada: a saída acima. A soma das junções é igual à soma de
//    frequência × profundidade das folhas. Com Fibonacci a árvore é uma
//    "escada": o símbolo de frequência 1 fica com um código de 7 bits.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 8

int main(void) {
    int folha[N] = {1, 1, 2, 3, 5, 8, 13, 21}; // já em ordem crescente
    (void)folha;

    return 0;
}
