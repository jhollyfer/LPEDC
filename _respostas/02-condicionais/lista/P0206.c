// Lista · Módulo 02 · Decisões
// Exercício P0206 · ★☆☆ · O Pix que passou do saldo

#include <stdio.h>

int main(void) {
    double saldo = 150.00;
    double pix = 200.00;

    saldo -= pix;
    printf("Saldo: R$ %.2f\n", saldo);
    if (saldo < 0) {
        printf("Você entrou no cheque especial.\n");
        printf("Juros do mês: R$ %.2f\n", -saldo * 0.08);
    } else {
        printf("Tudo certo com a conta.\n");
    }
    return 0;
}
