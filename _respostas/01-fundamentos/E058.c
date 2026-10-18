// 0010 · math.h
// Exercício E058 · ★★☆

#include <stdio.h>
#include <math.h>

int main(void) {
    double capital = 1000.00;
    double taxa = 0.01;

    double m12 = capital * pow(1 + taxa, 12);
    double m24 = capital * pow(1 + taxa, 24);
    double simples = capital + capital * taxa * 24;

    printf("12 meses: R$ %.2f (rendeu R$ %.2f)\n", m12, m12 - capital);
    printf("24 meses: R$ %.2f (rendeu R$ %.2f)\n", m24, m24 - capital);
    printf("Juros simples, 24 meses: R$ %.2f\n", simples);
    printf("Diferença: R$ %.2f\n", m24 - simples);
    return 0;
}
