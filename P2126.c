// Lista · Módulo 21 · Programação dinâmica
// Exercício P2126 · ★★★ · Subsequência crescente em O(n log n)
//
// A PD O(n²) da subsequência crescente máxima fica lenta com 1 milhão de
// valores. Existe um jeito O(n log n): mantenha fim[k] = o MENOR valor que
// termina uma subsequência crescente de tamanho k + 1 achada até agora. O
// vetor fim[] é sempre crescente, então, para cada valor x, uma BUSCA
// BINÁRIA acha a primeira posição com fim[k] >= x: x substitui fim[k] (ou
// estende o vetor, se maior que todos). O tamanho de fim[] é a resposta.
//
// Na academia, a carga do supino (kg) em 16 treinos seguidos foi:
//
//   40 42 38 45 43 47 41 50 48 52 44 55 53 49 58 60
//
// Escreva do zero, guardando o ÍNDICE do valor em cada fim[k] e, para cada
// treino, o índice do anterior na sequência (ant[]), para reconstruir a
// maior sequência de treinos com carga sempre crescente.
//
//   Saída esperada:
//   Maior sequência crescente: 9 treinos
//   Cargas: 40 42 43 47 48 52 53 58 60
//
// Dicas:
// 1. Guarde idx[k] (o índice do valor que está em fim[k]). Ao colocar x na
//    posição k, ant[i] = k > 0 ? idx[k - 1] : -1.
// 2. A reconstrução começa em idx[tam - 1] e segue ant[] até -1.
// 3. Resposta esperada: 9 treinos: 40 42 43 47 48 52 53 58 60. Há outras
//    de mesmo tamanho (40 42 45 47 50 52 55 58 60, por exemplo); o fim[]
//    com o menor final de cada tamanho leva a esta.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
