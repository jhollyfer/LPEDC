// A042 · O menu do caixa eletrônico

#include <stdio.h>

int main(void) {
    double saldo = 500.0;
    double valor;
    int opcao;

    do {
        printf("1 Saldo | 2 Sacar | 0 Sair: ");
        if (scanf("%d", &opcao) != 1) {
            opcao = 0; // entrada que não é número: encerra
        }

        switch (opcao) {
        case 1:
            printf("Saldo: R$ %.2f\n", saldo);
            break;
        case 2:
            printf("Valor do saque: ");
            if (scanf("%lf", &valor) == 1 && valor > 0 && valor <= saldo) {
                saldo = saldo - valor;
                printf("Retire R$ %.2f\n", valor);
            } else {
                printf("Saque recusado.\n");
            }
            break;
        case 0:
            printf("Até logo!\n");
            break;
        default:
            printf("Opção inválida.\n");
        }
    } while (opcao != 0); // o menu aparece pelo menos uma vez

    return 0;
}
// 1 Saldo | 2 Sacar | 0 Sair: 1
// Saldo: R$ 500.00
// 1 Saldo | 2 Sacar | 0 Sair: 2
// Valor do saque: 120
// Retire R$ 120.00
// 1 Saldo | 2 Sacar | 0 Sair: 2
// Valor do saque: 900
// Saque recusado.
// 1 Saldo | 2 Sacar | 0 Sair: 7
// Opção inválida.
// 1 Saldo | 2 Sacar | 0 Sair: 1
// Saldo: R$ 380.00
// 1 Saldo | 2 Sacar | 0 Sair: 0
// Até logo!
