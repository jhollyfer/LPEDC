// 0007 · Aritmética
// Exercício E039 · ★★☆

#include <stdio.h>

int main(void) {
    double conta;
    int pessoas;

    printf("Conta: R$ ");
    scanf("%lf", &conta);
    printf("Pessoas: ");
    scanf("%d", &pessoas);

    double servico = conta * 10 / 100;
    double total = conta + servico;

    printf("Serviço (10%%): R$ %.2f\n", servico);
    printf("Total: R$ %.2f\n", total);
    printf("Cada um: R$ %.2f\n", total / pessoas);
    return 0;
}
