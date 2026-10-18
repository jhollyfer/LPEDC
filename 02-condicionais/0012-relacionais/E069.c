// 0012 · Relacionais e a verdade em C
// Exercício E069 · ★★☆
//
// A loja cobra frete de R$ 24.90, mas só quando a compra é menor que
// R$ 199.00. Complete a linha do frete SEM usar if: use o 0 ou 1 de uma
// comparação dentro da conta.
//
//   Total da compra: R$ 150
//   Frete: R$ 24.90
//   A pagar: R$ 174.90
//
// Dicas:
// 1. (total < 199) vale 1 quando o frete é cobrado e 0 quando não é.
// 2. Multiplique essa comparação pelo valor do frete.
// 3. Resposta esperada: 150 → frete 24.90, paga 174.90; 210 → frete 0.00,
//    paga 210.00.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

int main(void) {
    double total;
    printf("Total da compra: R$ ");
    scanf("%lf", &total);

    double frete = 0; // troque o 0 por uma conta com comparação

    printf("Frete: R$ %.2f\n", frete);
    printf("A pagar: R$ %.2f\n", total + frete);
    return 0;
}
