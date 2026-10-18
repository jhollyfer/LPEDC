// 0034 · Parâmetros e passagem por valor
// Exercício E202 · ★★☆

#include <stdio.h>

double montante(double capital, double taxa, int meses) {
    for (int mes = 1; mes <= meses; mes++) {
        capital = capital * (1 + taxa / 100);
    }
    return capital;
}

int main(void) {
    double capital = 1000.00;

    printf("12 meses: R$ %.2f\n", montante(capital, 1, 12));
    printf("24 meses: R$ %.2f\n", montante(capital, 1, 24));
    printf("No main, capital continua R$ %.2f\n", capital);
    return 0;
}
