// 0030 · Escopo e tempo de vida
// Exercício E178 · ★★☆
//
// Previsão: Saldo: R$ 220.50 (300 - 45 - 1 - 32.50 - 1). A taxa escondida
// em preco_com_taxa mexe na global sem ninguém perceber pelo nome da função.

#include <stdio.h>

double gastar(double saldo, double valor) {
    double taxa = 1.00;
    return saldo - valor - taxa;
}

int main(void) {
    double saldo = 300.00;

    saldo = gastar(saldo, 45.00);
    saldo = gastar(saldo, 32.50);
    printf("Saldo: R$ %.2f\n", saldo);
    return 0;
}
