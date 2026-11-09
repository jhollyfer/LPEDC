// Lista · Módulo 04 · Funções e modularização
// Exercício P0404 · ★☆☆ · O reajuste que não chegou

#include <stdio.h>

double com_reajuste(double salario) {
    return salario * 1.05; // devolve o novo valor em vez de mexer na cópia
}

int main(void) {
    double salario = 2400.00;

    printf("Antes: R$ %.2f\n", salario);
    salario = com_reajuste(salario);
    printf("Depois: R$ %.2f\n", salario);
    return 0;
}
