// 0022 · For
// Exercício E129 · ★★☆

#include <math.h>
#include <stdio.h>

int main(void) {
    double inicial = 2000.0;
    double taxa = 0.008;
    double saldo = inicial;

    for (int mes = 1; mes <= 12; mes++) {
        saldo = saldo * (1 + taxa);
        printf("Mês %2d: R$ %.2f\n", mes, saldo);
    }
    printf("Pela fórmula: R$ %.2f\n", inicial * pow(1 + taxa, 12));
    return 0;
}
