// 0015 · if/else e o = no lugar do ==
// Exercício E088 · ★★☆

#include <stdio.h>

int main(void) {
    double salario, parcela;
    printf("Salário: ");
    if (scanf("%lf", &salario) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }
    printf("Parcela: ");
    if (scanf("%lf", &parcela) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    double limite = salario * 0.35;
    printf("Limite da parcela: R$ %.2f\n", limite);
    if (parcela <= limite) {
        printf("Aprovado!\n");
    } else {
        printf("Negado: a parcela passa do limite.\n");
    }
    return 0;
}
