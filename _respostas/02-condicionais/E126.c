// 0021 · else if, if aninhado e o else pendurado
// Exercício E126 · ★★★

#include <stdio.h>

int main(void) {
    double salario;
    printf("Salário: ");
    if (scanf("%lf", &salario) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    double imposto;
    if (salario <= 2000) {
        imposto = 0;
    } else if (salario <= 3000) {
        imposto = (salario - 2000) * 0.075;
    } else if (salario <= 4500) {
        imposto = 75 + (salario - 3000) * 0.15; // 75 = faixa de 7.5% cheia
    } else {
        imposto = 75 + 225 + (salario - 4500) * 0.225; // 225 = faixa de 15% cheia
    }
    printf("Imposto: R$ %.2f\n", imposto);
    return 0;
}
