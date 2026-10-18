// 0037 · Vetores
// Exercício E218 · ★☆☆
//
// Declare os dois vetores abaixo e escreva o código que mostra as quatro
// linhas da saída esperada. Nada de digitar os valores no printf: tudo tem de
// sair das gavetas, de laços e do sizeof.
//
//   int a[5] = {4, 2};
//   int b[] = {7, 8, 9};
//
//   1. Mostre as 5 gavetas de a, com o índice de cada uma.
//   2. Mostre quantos itens b tem, calculado com sizeof.
//   3. Com i indo de 4 a 8, mostre b[i % 3]: o resto faz o índice dar a volta
//      e nunca passar da última gaveta.
//   4. Guarde b[0] + b[1] em b[0] e mostre o novo b[0].
//
//   Saída esperada:
//   a[0]=4 a[1]=2 a[2]=0 a[3]=0 a[4]=0
//   b tem 3 itens
//   De 4 a 8: 8 9 7 8 9
//   Novo b[0]: 15
//
// Dicas:
// 1. Na inicialização parcial, as gavetas que faltam viram 0.
// 2. sizeof(b) / sizeof(b[0]) devolve size_t: mostre com %zu.
// 3. 4 % 3 é 1, 5 % 3 é 2, 6 % 3 é 0...
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
