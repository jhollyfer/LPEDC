// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2018 · ★★☆ · Quem tem maioria absoluta?
//
// Na eleição do síndico, os 15 votos (números dos candidatos) foram:
//
//   4 7 4 4 2 4 7 4 9 4 4 2 4 7 4
//
// Um candidato tem MAIORIA ABSOLUTA se recebeu mais da metade dos votos.
// Escreva do zero por divisão e conquista: se v[ini..fim] tem majoritário,
// ele é majoritário de pelo menos uma das metades. Então resolva as duas
// metades e, para cada candidato que voltar, conte os votos dele no
// pedaço inteiro. Devolva -1 se não houver. Mostre o resultado também para
// a apuração da segunda urna: 1 2 3 1 2 3 1 2.
//
//   Saída esperada:
//   Urna 1: candidato 4, com 9 de 15 votos
//   Urna 2: ninguém tem maioria
//
// Dicas:
// 1. Caso base: um voto só é majoritário de si mesmo.
// 2. conta(v, ini, fim, x) em O(n); a recorrência fica T(n) = 2T(n/2) +
//    O(n), ou seja, O(n log n).
// 3. Resposta esperada: na primeira urna, o 4, com 9 de 15 votos; na
//    segunda, ninguém.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
