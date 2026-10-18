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
// Teste com:
//   printf 'o rato roeu a roupa do rei de roma e o rei riu\n' | ~/LPEDC/rodar 25-estruturas-extras/0163-skip-list/E977.c
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
// Dicas:
// 1. Leia com while (scanf("%23s", palavra) == 1). O nó guarda uma CÓPIA
//    (char palavra[24] e strcpy). A cabeça pode ser um nó comum, com
//    andares = MAX e todos os prox em NULL.
// 2. A inserção é a do skip.c com strcmp no lugar do <: desça guardando
//    antes[k]; se antes[0]->prox[0] tem a palavra, some 1 e pronto; senão
//    sorteie os andares (comece em 1 e suba enquanto moeda() == 1, até MAX)
//    e ligue o nó em cada andar.
// 3. Resposta esperada: a saída acima (a ordem é a do strcmp; a forma dos
//    andares não muda a saída).
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
