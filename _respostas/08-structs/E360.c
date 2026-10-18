// 0060 · Typedef
// Exercício E360 · ★★★
//
// Resposta (b): Celsius errado = febre; não compila (o gcc diz "invalid
// initializer"; numa atribuição comum diria "incompatible types"). Cada
// struct é um tipo diferente, mesmo com campos iguais. Com typedef double Celsius e
// typedef double Fahrenheit, os dois seriam double: compilaria, e o erro de
// unidade passaria calado.

#include <stdio.h>

typedef struct {
    double graus;
} Celsius;

typedef struct {
    double graus;
} Fahrenheit;

Fahrenheit para_fahrenheit(Celsius c) {
    Fahrenheit f = {c.graus * 9 / 5 + 32};
    return f;
}

Celsius para_celsius(Fahrenheit f) {
    Celsius c = {(f.graus - 32) * 5 / 9};
    return c;
}

int main(void) {
    Celsius agua = {100.0};
    Fahrenheit febre = {98.6};

    printf("%.1f °C = %.1f °F\n", agua.graus, para_fahrenheit(agua).graus);
    printf("%.1f °F = %.1f °C\n", febre.graus, para_celsius(febre).graus);
    // Celsius errado = febre; // não compila: tipos incompatíveis
    return 0;
}
