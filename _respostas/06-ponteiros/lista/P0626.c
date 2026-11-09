// Lista · Módulo 06 · Ponteiros
// Exercício P0626 · ★★★ · O ponto de equilíbrio pela bisseção

#include <stdio.h>

double lucro(double x) { return -0.5 * x * x + 12 * x - 40; }
double cubica(double x) { return x * x * x - x - 2; }

double bissecao(double (*f)(double), double a, double b, double tol, int *voltas) {
    *voltas = 0;
    if (f(a) * f(b) > 0) {
        *voltas = -1; // sem troca de sinal: não há garantia de raiz
        return a;
    }
    while (b - a > tol) {
        double m = (a + b) / 2;
        if (f(a) * f(m) < 0) {
            b = m; // a raiz está na metade da esquerda
        } else {
            a = m;
        }
        (*voltas)++;
    }
    return (a + b) / 2;
}

void resolver(const char *nome, double (*f)(double), double a, double b) {
    int voltas;
    double r = bissecao(f, a, b, 0.0001, &voltas);
    if (voltas < 0) {
        printf("%s: sem troca de sinal em [%.1f, %.1f]\n", nome, a, b);
    } else {
        printf("%s: raiz %.4f em %d voltas (f = %.5f)\n", nome, r, voltas, f(r));
    }
}

int main(void) {
    resolver("lucro", lucro, 0, 10);
    resolver("x³ - x - 2", cubica, 1, 2);
    resolver("lucro", lucro, 5, 10);
    return 0;
}
