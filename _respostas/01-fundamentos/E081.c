// 0014 · Atribuição, ++ e --
// Exercício E081 · ★★☆

#include <stdio.h>

int main(void) {
    double saldo = 0.0;
    int depositos = 0;

    saldo += 15.00;
    depositos++;
    printf("Depósito %d: R$ %.2f\n", depositos, saldo);

    saldo += 20.00;
    depositos++;
    printf("Depósito %d: R$ %.2f\n", depositos, saldo);

    saldo += 12.50;
    depositos++;
    printf("Depósito %d: R$ %.2f\n", depositos, saldo);

    saldo -= 30.00;
    printf("Presente: R$ %.2f\n", saldo);

    saldo *= 1.01;
    printf("Rendimento: R$ %.2f\n", saldo);

    printf("%d depósitos\n", depositos);
    return 0;
}
