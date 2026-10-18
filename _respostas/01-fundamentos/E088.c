// 0015 · math.h
// Exercício E088 · ★★☆
//
// Resposta: com juros simples, seriam 1000 + 24 * 10 = R$ 1240.00. Nos
// compostos, cada mês rende 1% do montante, que inclui o que já rendeu; essa
// "renda da renda" fica maior a cada mês, e a diferença cresce.

#include <stdio.h>
#include <math.h>

int main(void) {
    double capital = 1000.00;
    double taxa = 0.01;

    double m12 = capital * pow(1 + taxa, 12);
    double m24 = capital * pow(1 + taxa, 24);

    printf("12 meses: R$ %.2f (rendeu R$ %.2f)\n", m12, m12 - capital);
    printf("24 meses: R$ %.2f (rendeu R$ %.2f)\n", m24, m24 - capital);
    return 0;
}
