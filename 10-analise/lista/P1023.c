// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1023 · ★★★ · Quem tem a maioria no grêmio?
//
// Na eleição do grêmio estudantil, um candidato só leva no primeiro turno se
// tiver MAIS DA METADE dos votos. Escreva duas funções que devolvem o
// candidato da maioria (ou -1 se não houver) e contam as comparações:
//
//   int maioria_ingenua(const int v[], int n, long *comp)
//     para cada i, conta quantas vezes v[i] aparece no vetor inteiro (n
//     comparações) e devolve assim que achar um com mais de n / 2;
//   int maioria_boyer_moore(const int v[], int n, long *comp)
//     fase 1: um candidato e um contador; para cada voto, se o contador é 0,
//     o voto vira o candidato; se o voto é igual ao candidato, contador++;
//     senão, contador--. Fase 2: conta os votos do candidato para confirmar.
//     Conte 1 comparação por voto em cada fase.
//
// Eleição 1: 1, 3, 2, 2, 1, 2, 2, 3, 2, 2, 2. Eleição 2: 1, 2, 3, 1, 2, 3, 1.
//
//   Saída esperada:
//   Eleição 1: candidato 2 com 7 de 11 votos
//     ingênuo: 33 comparações, Boyer-Moore: 22
//   Eleição 2: ninguém tem maioria
//     ingênuo: 49 comparações, Boyer-Moore: 14
//
// Dicas:
// 1. Por que a fase 1 funciona: cada "contador--" cancela um voto do
//    candidato contra um voto de outro. Quem tem mais da metade não pode ser
//    cancelado por inteiro, então sobra no fim.
// 2. A fase 2 é obrigatória: na eleição 2 a fase 1 termina com um candidato
//    (o 1), mas ele tem só 3 de 7.
// 3. O ingênuo é O(n²) no pior caso (sem maioria, n · n); Boyer-Moore é
//    O(n) e usa O(1) de memória extra.
// 4. Resposta esperada: a saída acima. Imprima a contagem de votos na
//    eleição 1 com mais um laço.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
