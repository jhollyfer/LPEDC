// 0072 · Notação O: como o custo cresce
// Exercício E428 · ★☆☆

#include <math.h>
#include <stdio.h>

// As fórmulas dos colegas.
double f_a(double n) { return 3 * n * n + 10 * n + 7; }
double f_b(double n) { (void)n; return 500; }
double f_c(double n) { return n + log2(n); }
double f_d(double n) { return 2 * n * log2(n) + 50 * n; }
double f_e(double n) { return n * n * n / 1000 + n * n; }
double f_f(double n) { return n * (n + 1) / 2; }

// As apostas de classe: o termo que domina, sem constante.
double g_a(double n) { return n * n; }
double g_b(double n) { (void)n; return 1; }
double g_c(double n) { return n; }
double g_d(double n) { return n * log2(n); }
double g_e(double n) { return n * n * n; }
double g_f(double n) { return n * n; }

void linha(const char *rotulo, double (*f)(double), double (*g)(double)) {
    printf("%-14s", rotulo);
    double ns[3] = {10, 1000, 1000000};
    for (int k = 0; k < 3; k++) {
        printf(" %10.4f", f(ns[k]) / g(ns[k]));
    }
    printf("\n");
}

int main(void) {
    printf("%-14s %10s %10s %10s\n", "fórmula", "n=10", "n=1000", "n=10^6");
    linha("a) O(n^2)", f_a, g_a);
    linha("b) O(1)", f_b, g_b);
    linha("c) O(n)", f_c, g_c);
    linha("d) O(n log n)", f_d, g_d);
    linha("e) O(n^3)", f_e, g_e);
    linha("f) O(n^2)", f_f, g_f);
    return 0;
}
