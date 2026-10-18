// 0025 · Padrões de laço
// Exercício E146 · ★☆☆

#include <stdio.h>

int main(void) {
    double gasto, total = 0.0;
    int quantos = 0;

    printf("Gasto (0 encerra): ");
    if (scanf("%lf", &gasto) != 1) {
        gasto = 0;
    }
    while (gasto != 0) {
        total = total + gasto;
        quantos++;
        printf("Gasto (0 encerra): ");
        if (scanf("%lf", &gasto) != 1) {
            gasto = 0;
        }
    }
    if (quantos > 0) {
        printf("Total: R$ %.2f em %d gastos\n", total, quantos);
        printf("Média: R$ %.2f\n", total / quantos);
    }
    return 0;
}
