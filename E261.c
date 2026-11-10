// 0044 · Memória e endereços
// Exercício E261 · ★★☆
//
// A lanchonete guarda o preço de 2 tamanhos (linhas) de 3 sucos (colunas)
// numa matriz double precos[2][3]:
//
//   { {6.0, 7.5, 8.0}, {9.0, 11.0, 12.5} }
//
// Mostre o valor e o endereço de cada posição, linha por linha, com dois
// for aninhados. Depois mostre, com sizeof, quantos bytes ocupa uma
// posição, uma linha inteira (precos[0]) e a matriz toda. Compare os
// endereços de precos[0][2] e precos[1][0] na saída: a linha 1 começa logo
// onde a linha 0 acaba.
//
//   Saída esperada (endereços mudam a cada execução):
//   precos[0][0] = 6.00 em 0x7f...30
//   precos[0][1] = 7.50 em 0x7f...38
//   ...
//   precos[1][2] = 12.50 em 0x7f...58
//   uma posição: 8 bytes
//   uma linha: 24 bytes
//   a matriz: 48 bytes
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
