// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1922 · ★★★ · Palavras cruzadas 3 × 3
//
// A revistinha de passatempos tem uma cruzadinha 3 × 3 sem casas pretas:
// as 3 linhas (horizontais) e as 3 colunas (verticais) são palavras, e as
// 6 palavras têm que ser DIFERENTES. As palavras permitidas são:
//
//   ALA AMO ARO ASA MAL MAR MAU OCA OLA RUA PAU SAL
//
// Escreva do zero um backtracking que escolhe a palavra de cada linha e
// poda cedo: depois de escolher a linha k, cada coluna tem k + 1 letras, e
// esse começo tem que ser começo de alguma palavra da lista (senão nenhuma
// escolha das linhas de baixo salva). Mostre cada grade achada (as 3
// linhas, separadas por / ) e quantas vezes o programa testou uma palavra
// numa linha.
//
//   Saída esperada:
//   AMO / SAL / ALA
//   ASA / MAL / OLA
//   Palavras testadas: 120
//
// Dicas:
// 1. eh_prefixo(p, tam) percorre a lista e compara as tam primeiras letras
//    com strncmp.
// 2. Na linha 2 (a última), o começo da coluna já tem 3 letras: aí
//    eh_prefixo vira "é palavra". No fim, confira que as 6 palavras são
//    diferentes (3 linhas e 3 colunas).
// 3. Resposta esperada: 2 grades, AMO / SAL / ALA e ASA / MAL / OLA (uma é
//    a outra virada: as linhas de uma são as colunas da outra).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
