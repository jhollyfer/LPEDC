// Lista · Módulo 01 · Fundamentos de C
// Exercício P0104 · ★☆☆ · O termômetro importado

#include <stdio.h>

int main(void) {
    double fahrenheit = 98.6;
    double celsius = 5.0 / 9 * (fahrenheit - 32); // 5.0 força a divisão real

    printf("%.1f F = %.1f C\n", fahrenheit, celsius);
    return 0;
}
