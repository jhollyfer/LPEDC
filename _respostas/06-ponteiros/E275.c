// 0046 · Passagem por referência
// Exercício E275 · ★★★

#include <stdio.h>
#include <math.h>

int raizes(double a, double b, double c, double *x1, double *x2) {
    if (a == 0) {
        return -1;
    }
    double delta = b * b - 4 * a * c;
    if (delta < 0) {
        return 0;
    }
    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);
    return delta == 0 ? 1 : 2;
}

void resolve(const char *texto, double a, double b, double c) {
    double x1, x2;
    int n = raizes(a, b, c, &x1, &x2);

    printf("%s  ->  ", texto);
    if (n == -1) {
        printf("não é do 2º grau\n");
    } else if (n == 0) {
        printf("nenhuma raiz real\n");
    } else if (n == 1) {
        printf("1 raiz: %.2f\n", x1);
    } else {
        printf("2 raízes: %.2f e %.2f\n", x1, x2);
    }
}

int main(void) {
    resolve("x² - 5x + 6 = 0 ", 1, -5, 6);
    resolve("x² + 2x + 1 = 0 ", 1, 2, 1);
    resolve("x² + 1 = 0      ", 1, 0, 1);
    resolve("0x² + 3x + 1 = 0", 0, 3, 1);
    return 0;
}
