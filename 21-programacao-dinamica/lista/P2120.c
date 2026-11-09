// Lista · Módulo 21 · Programação dinâmica
// Exercício P2120 · ★★☆ · Quantas árvores de busca diferentes?
//
// Com as chaves 1, 2 e 3 dá para montar 5 árvores binárias de busca
// diferentes (raiz 1, 2 ou 3, e as formas das subárvores). Quantas há com
// n chaves? Escolhendo a raiz r, as r - 1 chaves menores formam a
// subárvore esquerda e as n - r maiores a direita, e cada combinação vale:
//
//   arv(0) = 1;   arv(n) = soma, para r de 1 a n, de arv(r - 1) · arv(n - r)
//
// Esses são os números de CATALAN. Escreva do zero a versão memoizada
// (de cima para baixo, com memo[] e -1 em "não sei") e mostre arv(n) para
// n de 1 a 15, contando quantas vezes a soma foi de fato calculada.
//
//   Saída esperada:
//   n =  1: 1
//   n =  2: 2
//   n =  3: 5
//   n =  4: 14
//   n =  5: 42
//   n =  6: 132
//   n =  7: 429
//   n =  8: 1430
//   n =  9: 4862
//   n = 10: 16796
//   n = 11: 58786
//   n = 12: 208012
//   n = 13: 742900
//   n = 14: 2674440
//   n = 15: 9694845
//   Cálculos: 16
//
// Dicas:
// 1. Use long long: arv(15) passa de 9 milhões.
// 2. Conte calculos++ só quando a função passa do teste do memo (quando
//    vai realmente somar).
// 3. Resposta esperada: 1, 2, 5, 14, 42, ... até 9694845, com 16 cálculos
//    (um para cada n de 0 a 15): sem memo, arv(15) faria milhões de
//    chamadas.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
