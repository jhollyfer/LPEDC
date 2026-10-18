// 0020 · if/else e o = no lugar do ==
// Exercício E116 · ★☆☆

#include <stdio.h>

int main(void) {
    double salario;
    printf("Salário: ");
    if (scanf("%lf", &salario) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    double novo;
    if (salario <= 2000) {
        novo = salario * 1.10;
    } else {
        novo = salario * 1.06;
    }
    printf("Novo salário: R$ %.2f\n", novo);
    return 0;
}
