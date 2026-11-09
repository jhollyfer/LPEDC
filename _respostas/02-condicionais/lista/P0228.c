// Lista · Módulo 02 · Decisões
// Exercício P0228 · ★★★ · O saque-aniversário do FGTS

#include <stdio.h>

int main(void) {
    double saldo;

    printf("Saldo do FGTS: ");
    if (scanf("%lf", &saldo) != 1 || saldo < 0) {
        printf("Saldo inválido.\n");
        return 1;
    }

    int faixa;
    double aliquota, parcela;
    if (saldo <= 500.00) {
        faixa = 1; aliquota = 0.50; parcela = 0.00;
    } else if (saldo <= 1000.00) {
        faixa = 2; aliquota = 0.40; parcela = 50.00;
    } else if (saldo <= 5000.00) {
        faixa = 3; aliquota = 0.30; parcela = 150.00;
    } else if (saldo <= 10000.00) {
        faixa = 4; aliquota = 0.20; parcela = 650.00;
    } else if (saldo <= 15000.00) {
        faixa = 5; aliquota = 0.15; parcela = 1150.00;
    } else if (saldo <= 20000.00) {
        faixa = 6; aliquota = 0.10; parcela = 1900.00;
    } else {
        faixa = 7; aliquota = 0.05; parcela = 2900.00;
    }

    printf("Faixa %d: %.0f%% + R$ %.2f\n", faixa, aliquota * 100, parcela);
    printf("Saque liberado: R$ %.2f\n", saldo * aliquota + parcela);
    return 0;
}
