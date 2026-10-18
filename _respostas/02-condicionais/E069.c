// 0012 · Relacionais e a verdade em C
// Exercício E069 · ★★☆

#include <stdio.h>

int main(void) {
    double total;
    printf("Total da compra: R$ ");
    scanf("%lf", &total);

    double frete = (total < 199) * 24.90; // 1 * 24.90 ou 0 * 24.90

    printf("Frete: R$ %.2f\n", frete);
    printf("A pagar: R$ %.2f\n", total + frete);
    return 0;
}
