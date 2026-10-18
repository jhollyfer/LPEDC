// 0065 · Typedef
// Exercício E389 · ★★★

#include <stdio.h>

typedef double (*Operacao)(double, double);

typedef struct {
    char simbolo;
    Operacao f;
} Botao;

double somar(double a, double b) { return a + b; }
double subtrair(double a, double b) { return a - b; }
double multiplicar(double a, double b) { return a * b; }
double dividir(double a, double b) { return a / b; }

int main(void) {
    Botao botoes[] = {{'+', somar}, {'-', subtrair}, {'*', multiplicar}, {'/', dividir}};
    int n = sizeof botoes / sizeof botoes[0];

    for (int i = 0; i < n; i++) {
        printf("12 %c 4 = %g\n", botoes[i].simbolo, botoes[i].f(12, 4));
    }
    return 0;
}
