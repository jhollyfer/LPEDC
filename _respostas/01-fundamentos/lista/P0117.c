// Lista · Módulo 01 · Fundamentos de C
// Exercício P0117 · ★★☆ · O ângulo dos ponteiros

#include <math.h>
#include <stdio.h>

int main(void) {
    int h1 = 14, m1 = 20;
    int h2 = 9, m2 = 45;

    double angulo1 = fabs((30 * (h1 % 12) + 0.5 * m1) - 6 * m1);
    double angulo2 = fabs((30 * (h2 % 12) + 0.5 * m2) - 6 * m2);

    printf("%02d:%02d -> %.1f graus\n", h1, m1, angulo1);
    printf("%02d:%02d -> %.1f graus\n", h2, m2, angulo2);
    return 0;
}
