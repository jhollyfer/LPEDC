// Lista · Módulo 02 · Decisões
// Exercício P0211 · ★★☆ · A nota do jurado do meio

#include <stdio.h>

int main(void) {
    double a = 7.5, b = 9.0, c = 8.0;
    double meio;

    if ((a >= b && a <= c) || (a <= b && a >= c)) {
        meio = a;
    } else if ((b >= a && b <= c) || (b <= a && b >= c)) {
        meio = b;
    } else {
        meio = c;
    }

    printf("Notas: %.1f %.1f %.1f\n", a, b, c);
    printf("Nota do meio: %.1f\n", meio);
    return 0;
}
