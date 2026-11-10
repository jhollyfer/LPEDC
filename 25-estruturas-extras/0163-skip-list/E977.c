// 0163 · Skip list
// Exercício E977 · ★★★
//
// Contador de palavras com skip list. Escreva do zero (sem o skip.h, que só
// guarda int) uma skip list de palavras: cada nó tem a palavra (até 23
// letras), quantas vezes ela apareceu, os andares e o vetor prox. Leia as
// palavras da entrada até o fim; palavra nova entra no lugar certo (ordem
// do strcmp) com andares sorteados por moeda(); palavra repetida só soma 1.
// No fim, mostre as palavras em ordem e libere tudo.
//
//   Entrada:
//   o rato roeu a roupa do rei de roma e o rei riu
//
//   Saída esperada:
//   a 1
//   de 1
//   do 1
//   e 1
//   o 2
//   rato 1
//   rei 2
//   riu 1
//   roeu 1
//   roma 1
//   roupa 1
//   11 palavras diferentes, 13 no total
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 8

// a moeda: 0 ou 1, sempre a mesma sequência
int moeda(void) {
    static unsigned estado = 42;
    estado = estado * 1103515245u + 12345u;
    return (estado >> 16) & 1;
}

int main(void) {

    return 0;
}
