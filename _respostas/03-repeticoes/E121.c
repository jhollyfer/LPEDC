// 0021 · Do-while
// Exercício E121 · ★☆☆

#include <stdio.h>

int main(void) {
    double nota;

    do {
        printf("Nota (0 a 10): ");
        if (scanf("%lf", &nota) != 1) {
            return 1;
        }
    } while (nota < 0 || nota > 10);

    printf("Nota aceita: %.1f\n", nota);
    return 0;
}
