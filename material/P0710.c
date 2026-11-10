// Lista · Módulo 07 · Memória dinâmica
// Exercício P0710 · ★☆☆ · Somar duas matrizes dinâmicas
//
// Duas filiais de uma loja de celulares anotaram as vendas de 3 modelos
// (linhas) em 2 meses (colunas). As matrizes foram criadas no heap, com o
// tamanho que só se sabe na hora de rodar:
//
//   filial A: 14 9 / 6 11 / 20 17
//   filial B: 8 12 / 3 5 / 15 22
//
// Escreva int **somar(int **a, int **b, int l, int c), que devolve uma
// matriz NOVA com a soma. Use criar e liberar (do P0708). Mostre a soma e
// libere as três matrizes:
//
//   Saída esperada:
//   Total das filiais:
//   Modelo 1:  22  21
//   Modelo 2:   9  16
//   Modelo 3:  35  39
//
// Dicas:
// 1. Para preencher A e B a partir dos números, use vetores fixos de 6
//    posições e o índice i * c + j.
// 2. São três matrizes de 3 linhas: três chamadas de liberar(x, 3).
// 3. Se alguma criação falhar, libere as que já existem (liberar aceita
//    NULL).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
