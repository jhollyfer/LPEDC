// 0030 · Escopo e tempo de vida
// Exercício E178 · ★★☆

#include <stdio.h>

// recebe o saldo, devolve o saldo novo: a taxa aparece aqui, à vista
double gastar(double saldo, double valor) {
    double taxa = 1.00;
    return saldo - valor - taxa;
}

int main(void) {
    double saldo = 300.00; // local: só o main mexe

    saldo = gastar(saldo, 45.00);
    saldo = gastar(saldo, 32.50);
    printf("Saldo: R$ %.2f\n", saldo);

    saldo = gastar(saldo, 18.00);
    printf("Saldo: R$ %.2f\n", saldo);
    return 0;
}
