// 0055 · Ponteiro para função
// Exercício E327 · ★★☆

#include <stdio.h>

int soma(int a, int b) { return a + b; }
int subtrai(int a, int b) { return a - b; }
int multiplica(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int main(void) {
    int (*ops[4])(int, int) = {soma, subtrai, multiplica, divide};
    const char *simbolos = "+-*/";
    int a, b;
    char op;

    printf("Digite a conta: ");
    if (scanf("%d %c %d", &a, &op, &b) != 3) {
        printf("Entrada inválida\n");
        return 1;
    }

    int indice = -1;
    for (int i = 0; simbolos[i] != '\0'; i++) {
        if (simbolos[i] == op) {
            indice = i;
        }
    }

    if (indice < 0) {
        printf("Operador inválido\n");
    } else if (op == '/' && b == 0) {
        printf("Divisão por zero\n");
    } else {
        printf("Resultado: %d\n", ops[indice](a, b));
    }
    return 0;
}
