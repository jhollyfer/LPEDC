// 0060 · Typedef
// Exercício E360 · ★★★

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
    // Celsius errado = febre;  -> não compila ("invalid initializer"): cada
    // struct é um tipo diferente. Com typedef double, passaria calado.
    Celsius febre_c = para_celsius(febre);
    printf("%.1f °C: %s\n", febre_c.graus, febre_c.graus >= 37.5 ? "febre" : "sem febre");
    return 0;
}
