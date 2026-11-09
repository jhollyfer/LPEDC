// Lista · Módulo 01 · Fundamentos de C
// Exercício P0104 · ★☆☆ · O termômetro importado
//
// O termômetro que veio de fora mostra 98.6 °F. O programa abaixo deveria
// converter para Celsius com C = 5 / 9 × (F − 32), mas mostra 0.0. O erro está
// na conta, de propósito. Conserte só a linha da conversão:
//
//   Saída esperada:
//   98.6 F = 37.0 C
//
// Dicas:
// 1. Calcule na mão quanto vale 5 / 9 em C quando os dois são int.
// 2. Basta um dos lados ser double: 5.0 / 9 já dá 0.5555...
// 3. Resposta esperada: 98.6 F = 37.0 C.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    double fahrenheit = 98.6;
    double celsius = 5 / 9 * (fahrenheit - 32);

    printf("%.1f F = %.1f C\n", fahrenheit, celsius);
    return 0;
}
