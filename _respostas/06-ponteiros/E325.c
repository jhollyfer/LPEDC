// 0055 · Ponteiro para função
// Exercício E325 · ★☆☆

#include <stdio.h>

double c_para_f(double c) { return c * 9 / 5 + 32; }
double f_para_c(double f) { return (f - 32) * 5 / 9; }

int main(void) {
    double (*conv)(double);

    conv = c_para_f;
    printf("30.0 -> %.1f\n", conv(30));
    conv = f_para_c;
    printf("86.0 -> %.1f\n", conv(86));
    return 0;
}
