// 0019 · if
// Exercício E114 · ★★★

#include <stdio.h>

int main(void) {
    int consumo;
    printf("Consumo (m³): ");
    if (scanf("%d", &consumo) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    double valor = 45.00; // tarifa mínima
    if (consumo > 10) {
        valor = valor + (consumo - 10) * 6.20;
    }
    if (consumo > 30) {
        valor = valor * 1.15; // multa por desperdício
    }
    printf("Conta: R$ %.2f\n", valor);
    return 0;
}
