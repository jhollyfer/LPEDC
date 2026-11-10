// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2005 · ★☆☆ · A melhor semana da lanchonete
//
// A lanchonete anotou o lucro (ou prejuízo) de 10 dias, em reais:
//
//   dia:    0    1    2    3    4    5    6    7    8    9
//   lucro: -40  120  -30   80  -150  60   90  -20   70  -60
//
// Qual sequência de dias SEGUIDOS deu o maior lucro somado? Escreva do
// zero o subvetor de soma máxima por divisão e conquista (assunto 0132),
// mas devolvendo também ONDE ele começa e termina: use um struct Trecho {
// int ini, fim, soma; }. O trecho que cruza o meio é o melhor final da
// esquerda grudado no melhor começo da direita.
//
//   Saída esperada:
//   Melhor trecho: dias 1 a 8
//   Lucro: R$ 220
//
// Dicas:
// 1. Caso base: um dia só é o trecho (i, i, v[i]).
// 2. Cruzando: a partir de meio, ande para a esquerda guardando a maior
//    soma e onde ela começa; a partir de meio + 1, para a direita
//    guardando a maior soma e onde ela termina.
// 3. Resposta esperada: dias 1 a 8, lucro de R$ 220. Vale a pena atravessar
//    o prejuízo de R$ 150 do dia 4: os dias 5 a 8 sozinhos dão R$ 200.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
