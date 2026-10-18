// 0011 · Juntando tudo
// Exercício E062 · ★☆☆

#include <stdio.h>

#define ZERO_ABSOLUTO 273.15

int main(void) {
    double celsius;

    printf("Celsius: ");
    scanf("%lf", &celsius);

    double fahrenheit = celsius * 9.0 / 5 + 32;
    double kelvin = celsius + ZERO_ABSOLUTO;

    printf("%.1f °C = %.1f °F = %.2f K\n", celsius, fahrenheit, kelvin);
    return 0;
}
