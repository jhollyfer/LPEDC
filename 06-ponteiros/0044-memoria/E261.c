// 0044 · Memória e endereços
// Exercício E261 · ★★☆
//
// A lanchonete guarda o preço de 2 tamanhos (linhas) de 3 sucos (colunas)
// numa matriz double precos[2][3]:
//
//   { {6.0, 7.5, 8.0}, {9.0, 11.0, 12.5} }
//
// Mostre o endereço de cada posição, linha por linha, com dois for
// aninhados. Depois responda: de quanto em quanto os endereços sobem? Onde
// começa a linha 1 em relação ao fim da linha 0?
//
//   Saída esperada (endereços mudam a cada execução):
//   precos[0][0] = 6.00 em 0x7f...30
//   precos[0][1] = 7.50 em 0x7f...38
//   ...
//   precos[1][2] = 12.50 em 0x7f...58
//
// Dicas:
// 1. &precos[i][j] dá o endereço de uma posição.
// 2. Olhe só os dois últimos dígitos hexa: 0x30, 0x38, 0x40...
// 3. Resposta esperada: sobem de 8 em 8 (sizeof(double)); precos[1][0]
//    fica logo depois de precos[0][2], sem buraco: a matriz é uma fila só
//    de 6 doubles, linha após linha (assunto 0039).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
