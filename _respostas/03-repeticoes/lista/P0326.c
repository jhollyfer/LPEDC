// Lista · Módulo 03 · Laços
// Exercício P0326 · ★★★ · A tabela do empréstimo

#include <math.h>
#include <stdio.h>

int main(void) {
    const double VALOR = 1200.00;
    const double TAXA = 0.02;
    const int N = 6;

    double parcela = VALOR * TAXA / (1 - pow(1 + TAXA, -N));
    double saldo = VALOR;
    double total_juros = 0.0;

    printf("Parcela: R$ %.2f\n", parcela);
    printf("Mês  Juros   Amortização  Saldo\n");
    for (int mes = 1; mes <= N; mes++) {
        double juros = saldo * TAXA;
        double amortizacao = parcela - juros;
        saldo -= amortizacao;
        total_juros += juros;
        if (fabs(saldo) < 0.005) {
            saldo = 0.0;
        }
        printf("%2d  %6.2f  %10.2f  %8.2f\n", mes, juros, amortizacao, saldo);
    }
    printf("Total pago: R$ %.2f\n", parcela * N);
    printf("Total de juros: R$ %.2f\n", total_juros);
    return 0;
}
