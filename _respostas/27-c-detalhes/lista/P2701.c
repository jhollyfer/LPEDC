// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2701 · ★☆☆ · A calculadora do caixa

#include <stdio.h>

int calcular(int a, char op, int b, int *resultado) {
    switch (op) {
    case '+':
        *resultado = a + b;
        return 1;
    case '-':
        *resultado = a - b;
        return 1;
    case '*':
        *resultado = a * b;
        return 1;
    case '/':
        if (b == 0) {
            return 0;
        }
        *resultado = a / b;
        return 1;
    default:
        return -1;
    }
}

int main(void) {
    int as[] = {12, 12, 12, 12, 7, 12};
    char ops[] = {'+', '-', '*', '/', '/', '%'};
    int bs[] = {5, 5, 5, 5, 0, 5};
    for (int i = 0; i < 6; i++) {
        int r;
        int status = calcular(as[i], ops[i], bs[i], &r);
        if (status == 1) {
            printf("%d %c %d = %d\n", as[i], ops[i], bs[i], r);
        } else if (status == 0) {
            printf("%d %c %d: divisão por zero\n", as[i], ops[i], bs[i]);
        } else {
            printf("%d %c %d: operação inválida\n", as[i], ops[i], bs[i]);
        }
    }
    return 0;
}
