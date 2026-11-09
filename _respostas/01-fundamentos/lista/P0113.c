// Lista · Módulo 01 · Fundamentos de C
// Exercício P0113 · ★★☆ · A média ponderada do concurso

#include <stdio.h>

int main(void) {
    double objetiva = 6.0;
    double discursiva = 8.0;

    double media = (objetiva * 2 + discursiva * 3) / 5;

    printf("Média final: %.1f\n", media);
    return 0;
}
