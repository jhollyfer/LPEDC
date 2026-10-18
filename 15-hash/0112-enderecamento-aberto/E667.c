// 0112 · Endereçamento aberto
// Exercício E667 · ★☆☆
//
// Escreva um programa com uma tabela de 7 inteiros, todos começando com -1
// (livre), que insere 10, 24, 5, 17 e 31 com sondagem linear (h = k % 7; se
// ocupada, tenta a próxima, dando a volta no fim) e mostra a tabela.
//
//   Saída esperada:
//   [0] 31
//   [1] -
//   [2] -
//   [3] 10
//   [4] 24
//   [5] 5
//   [6] 17
//
// Dicas:
// 1. Um while que anda enquanto tab[i] != -1, com i = (i + 1) % 7.
// 2. Faça à mão antes: 10, 24, 17 e 31 têm hash 3; o 5 tem hash 5.
// 3. Resposta esperada: a saída acima. O 31 tenta 3, 4, 5 e 6, todas
//    ocupadas, dá a volta e para na 0.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
