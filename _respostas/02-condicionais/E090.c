// 0015 · if/else e o = no lugar do ==
// Exercício E090 · ★★★

#include <math.h>
#include <stdio.h>

int main(void) {
    double a, b, c;
    printf("Coeficientes a b c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Entrada inválida\n");
        return 1;
    }

    double delta = b * b - 4 * a * c;
    if (delta < 0) {
        printf("Sem raízes reais.\n");
    } else {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    }
    return 0;
}
