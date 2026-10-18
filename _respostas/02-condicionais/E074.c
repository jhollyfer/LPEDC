// 0013 · Lógicos: E, OU, NÃO
// Exercício E074 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    double temp;
    printf("Temperatura: ");
    scanf("%lf", &temp);

    bool dentro = temp >= 2 && temp <= 8;
    bool alarme = !dentro;

    printf("Dentro da faixa? %d\n", dentro);
    printf("Alarme? %d\n", alarme);
    return 0;
}
