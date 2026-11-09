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
//    1 chaves: 1 árvores
//    2 chaves: 2 árvores
//    3 chaves: 5 árvores
//    4 chaves: 14 árvores
//    5 chaves: 42 árvores
//    6 chaves: 132 árvores
//    7 chaves: 429 árvores
//    8 chaves: 1430 árvores
//    9 chaves: 4862 árvores
//   10 chaves: 16796 árvores
//   11 chaves: 58786 árvores
//   12 chaves: 208012 árvores
//   13 chaves: 742900 árvores
//   14 chaves: 2674440 árvores
//   15 chaves: 9694845 árvores
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
