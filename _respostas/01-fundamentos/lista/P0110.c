// Lista · Módulo 01 · Fundamentos de C
// Exercício P0110 · ★☆☆ · Açaí no quilo

#include <stdio.h>

int main(void) {
    double peso, preco;

    printf("Peso (kg): ");
    scanf("%lf", &peso);
    printf("Preço do quilo: ");
    scanf("%lf", &preco);

    printf("Total: R$ %.2f\n", peso * preco);
    return 0;
}
