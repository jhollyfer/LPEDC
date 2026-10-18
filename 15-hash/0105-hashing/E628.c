// 0105 · A ideia e a função hash
// Exercício E628 · ★★☆
//
// Na loja de material de construção, todo código de produto termina em 0:
// 120, 350, 470, 590, 610, 230, 740, 860, 980 e 440. Escreva um programa que
// espalha esses 10 códigos com "codigo % m" e mostra quantos caíram em cada
// balde, com uma estrela por código. No fim de cada tabela, mostre quantos
// baldes ficaram vazios. Faça para m = 10 e para m = 11.
//
//   Saída esperada (começo):
//   m = 10
//    0: **********
//    1:
//   ...
//   vazios: 9
//
// Dicas:
// 1. Um vetor "int conta[11] = {0};" e "conta[codigo % m]++" para cada código.
// 2. Faça uma função "void distribui(const int codigos[], int n, int m)"
//    e chame duas vezes.
// 3. Resposta esperada: com m = 10, os 10 códigos caem no balde 0
//    (vazios: 9). Com m = 11: um código em cada balde, menos o 4 e o 6
//    (vazios: 2) e o 10, com dois (120 e 230). Com m = 10, o resto só olha
//    o último dígito, que é sempre 0; um m primo usa o número inteiro.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
