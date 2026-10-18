// 0015 · math.h
// Exercício E090 · ★★★

#include <stdio.h>
#include <math.h>

int main(void) {
    double a = -5, b = 20, c = 1.5;

    double delta = b * b - 4 * a * c;
    double t_chao = (-b - sqrt(delta)) / (2 * a);

    double t_max = -b / (2 * a);
    double h_max = a * pow(t_max, 2) + b * t_max + c;

    printf("Delta: %.2f\n", delta);
    printf("Chega ao chão em %.2f s\n", t_chao);
    printf("Altura máxima: %.2f m, em %.2f s\n", h_max, t_max);
    return 0;
}
