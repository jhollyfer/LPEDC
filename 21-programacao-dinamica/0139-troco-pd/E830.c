// 0139 · Troco com programação dinâmica
// Exercício E830 · ★☆☆
//
// No basquete, cada cesta vale 1 (lance livre), 2 ou 3 pontos. Um time fez
// 10 pontos num quarto. Quantas COMBINAÇÕES de cestas dão 10 pontos? Aqui a
// ordem não importa: "3 + 3 + 2 + 2" e "2 + 3 + 2 + 3" são a mesma
// combinação (duas de três e duas de dois).
//
// Escreva um programa com um vetor jeitos[0..10] e mostre o vetor inteiro e
// a resposta.
//
//   Saída esperada:
//   jeitos: 1 1 2 3 4 5 7 8 10 12 14
//   Combinações de cestas que dão 10 pontos: 14
//
// Dicas:
// 1. jeitos[0] = 1 (zero pontos: nenhuma cesta) e o resto começa em 0.
// 2. Laço de FORA no tipo de cesta, laço de dentro nos pontos, de c até 10:
//    jeitos[v] += jeitos[v - c].
// 3. Com os laços na ordem trocada, você contaria sequências (a ordem das
//    cestas no jogo), e o resultado seria bem maior.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
