// 0019 · if
// Exercício E109 · ★☆☆

#include <stdio.h>

int main(void) {
    double temp;
    printf("Temperatura: ");
    if (scanf("%lf", &temp) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    printf("Temperatura: %.1f °C\n", temp);
    if (temp > 37.5) {
        printf("Febre! Procure um médico.\n");
    }
    return 0;
}
