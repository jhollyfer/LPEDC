// 0023 · switch, case, break e fall-through
// Exercício E134 · ★☆☆

#include <stdio.h>

int main(void) {
    double salario;
    char classe;
    printf("Salário: ");
    if (scanf("%lf", &salario) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }
    printf("Classe (A, B ou C): ");
    if (scanf(" %c", &classe) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    double aumento;
    switch (classe) {
    case 'A':
    case 'a':
        aumento = 0.10;
        break;
    case 'B':
    case 'b':
        aumento = 0.15;
        break;
    case 'C':
    case 'c':
        aumento = 0.20;
        break;
    default:
        printf("Classe inválida.\n");
        return 1;
    }
    printf("Novo salário: R$ %.2f\n", salario * (1 + aumento));
    return 0;
}
