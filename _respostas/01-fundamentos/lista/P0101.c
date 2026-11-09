// Lista · Módulo 01 · Fundamentos de C
// Exercício P0101 · ★☆☆ · O plano trimestral da academia

#include <stdio.h>

int main(void) {
    double mensalidade = 119.90;
    double matricula = 49.90;
    int meses = 3;

    double total = mensalidade * meses + matricula;

    printf("Mensalidade: R$ %.2f\n", mensalidade);
    printf("Meses: %d\n", meses);
    printf("Total do plano: R$ %.2f\n", total);
    return 0;
}
