// Lista · Módulo 01 · Fundamentos de C
// Exercício P0115 · ★★☆ · O pace da corrida de rua

#include <stdio.h>

int main(void) {
    int distancia = 10; // km
    int segundos = 52 * 60 + 30;

    int pace = segundos / distancia; // segundos por km
    double velocidade = distancia / (segundos / 3600.0);

    printf("Tempo total: %d s\n", segundos);
    printf("Pace: %d:%02d por km\n", pace / 60, pace % 60);
    printf("Velocidade: %.2f km/h\n", velocidade);
    return 0;
}
