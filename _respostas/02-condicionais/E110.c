// 0019 · Juntando tudo: a conta de luz
// Exercício E110 · ★☆☆

#include <stdio.h>

int main(void) {
    int saldo = 500;
    int saque;
    printf("Valor do saque: ");
    if (scanf("%d", &saque) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    if (saque <= 0) {
        printf("Valor inválido.\n");
    } else if (saque % 10 != 0) {
        printf("O caixa só tem notas de 10.\n");
    } else if (saque > saldo) {
        printf("Saldo insuficiente.\n");
    } else {
        saldo -= saque;
        printf("Saque de R$ %d. Saldo: R$ %d\n", saque, saldo);
    }
    return 0;
}
