// 0140 · Mochila 0/1
// Exercício E835 · ★☆☆
//
// Uma padaria tem R$ 10 mil para investir e cinco projetos. Cada projeto é
// feito inteiro ou não é feito (0/1). Custos e retornos em mil reais:
//
//   projeto            custo  retorno por ano
//   1 fachada nova       4          9
//   2 site de pedidos    3          7
//   3 curso da equipe    2          4
//   4 forno novo         5         11
//   5 vitrine refrig.    1          2
//
// Escreva um programa que monta a tabela t[i][c] (maior retorno usando os
// projetos 1..i com c mil reais) e mostre a última linha da tabela e o
// retorno máximo com os R$ 10 mil.
//
//   Saída esperada:
//   última linha: 0 2 4 7 9 11 13 16 18 20 22
//   Retorno máximo com R$ 10 mil: R$ 22 mil por ano
//
// Dicas:
// 1. Use vetores com índice começando em 1 (custo[0] e retorno[0] sem uso) e
//    a matriz int t[6][11].
// 2. Linha 0 toda zero. Depois, para cada célula: t[i][c] = t[i - 1][c] e,
//    se custo[i] <= c, tente retorno[i] + t[i - 1][c - custo[i]].
// 3. A última linha diz o melhor retorno para cada orçamento de 0 a 10.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
