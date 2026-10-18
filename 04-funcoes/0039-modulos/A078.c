// A078 · O módulo guarda segredos

#include <stdio.h>

#include "conversao.h"

int main(void) {
    double maxima = 0;

    for (int dia = 1; dia <= 3; dia++) {
        double f = celsius_para_fahrenheit(20 + dia * 5); // 25, 30, 35 °C
        printf("Dia %d: %.1f °F\n", dia, f);
        maxima = f > maxima ? f : maxima;
    }
    printf("Máxima: %.1f °F\n", maxima);
    printf("Conversões feitas: %d\n", conversoes_feitas());

    // contador = 0;    // erro: 'contador' undeclared (é static em conversao.c)
    // contar(1.0);     // erro: contar não está no .h e é static: só existe lá
    return 0;
}
// Saída:
// Dia 1: 77.0 °F
// Dia 2: 86.0 °F
// Dia 3: 95.0 °F
// Máxima: 95.0 °F
// Conversões feitas: 3
