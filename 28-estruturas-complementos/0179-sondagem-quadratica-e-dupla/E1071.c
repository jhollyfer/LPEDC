// 0179 · Sondagem quadrática e dupla
// Exercício E1071 · ★★☆
//
// Dispersão dupla com m = 16, uma potência de 2. A regra do Cormen: o passo
// h2(k) tem que ser ÍMPAR, para ser primo com 16 e visitar todas as
// posições. Escreva, sem o TAD, h1(k) = k % 16 e h2(k) = 2 * ((k / 16) % 8)
// + 1 (os bits que o h1 não usa), e insira os cartões 3, 19, 35, 51, 67 e
// 83 (todos com h1 = 3) num vetor de 16 posições (-1 é livre). Mostre o h2,
// a posição e as sondagens de cada um e a tabela no fim.
//
//   Saída esperada:
//    3: h2 =  1 -> posição  3, 1 sondagens
//   19: h2 =  3 -> posição  6, 2 sondagens
//   35: h2 =  5 -> posição  8, 2 sondagens
//   51: h2 =  7 -> posição 10, 2 sondagens
//   67: h2 =  9 -> posição 12, 2 sondagens
//   83: h2 = 11 -> posição 14, 2 sondagens
//   tabela: . . . 3 . . 19 . 35 . 51 . 67 . 83 .
//
// Dicas:
// 1. A posição da i-ésima sondagem é (h1(k) + i * h2(k)) % 16.
// 2. Com sondagem linear, os seis ocupariam as posições 3 a 8 e o último
//    faria 6 sondagens.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
