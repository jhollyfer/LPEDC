// 0139 · Troco com programação dinâmica
// Exercício E829 · ★☆☆
//
// A loja de ferragens vende parafusos só em pacotes fechados de 3, 7 e 11
// unidades. Um marceneiro precisa de exatamente 25 parafusos e quer levar o
// menor número de pacotes. Escreva um programa que monta a tabela dp[v] (o
// menor número de pacotes com exatamente v parafusos) de 0 a 25. Mostre as
// quantidades de 1 a 25 que são impossíveis e a resposta para 25.
//
//   Saída esperada:
//   Impossíveis até 25: 1 2 4 5 8
//   Menor número de pacotes para 25 parafusos: 3
//
// Dicas:
// 1. dp[0] = 0; para cada v, comece com dp[v] = "infinito" e teste cada
//    pacote p <= v como o último: dp[v - p] + 1.
// 2. Um infinito seguro aqui é 26: ninguém precisa de mais que 25 pacotes, e
//    26 + 1 ainda cabe folgado num int.
// 3. Quem continuou com o infinito no fim é impossível.
// 4. Resposta esperada: a saída acima (25 = 11 + 7 + 7, ou 11 + 11 + 3).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
