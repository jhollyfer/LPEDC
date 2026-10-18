// 0018 · switch, case, break e fall-through
// Exercício E106 · ★★☆

#include <stdio.h>

int main(void) {
    double a, b;
    char op;
    printf("Conta: ");
    if (scanf("%lf %c %lf", &a, &op, &b) != 3) {
        printf("Entrada inválida\n");
        return 1;
    }

    switch (op) {
    case '+':
        printf("= %.2f\n", a + b);
        break;
    case '-':
        printf("= %.2f\n", a - b);
        break;
    case '*':
        printf("= %.2f\n", a * b);
        break;
    case '/':
        if (b == 0) {
            printf("Divisão por zero.\n");
        } else {
            printf("= %.2f\n", a / b);
        }
        break;
    default:
        printf("Operador inválido.\n");
    }
    return 0;
}
