// Lista · Módulo 01 · Fundamentos de C
// Exercício P0114 · ★★☆ · O barco para Parintins

#include <math.h>
#include <stdio.h>

int main(void) {
    double distancia = 369.0;
    double velocidade = 25.0;

    double horas = distancia / velocidade;
    int minutos_totais = (int)round(horas * 60);

    printf("Tempo: %.2f h\n", horas);
    printf("Em minutos: %d\n", minutos_totais);
    printf("Chegada em %d h e %d min de viagem\n", minutos_totais / 60, minutos_totais % 60);
    return 0;
}
