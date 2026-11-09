// Lista · Módulo 01 · Fundamentos de C
// Exercício P0102 · ★☆☆ · Gasolina até Itacoatiara

#include <stdio.h>

int main(void) {
    int distancia = 176;      // km
    double consumo = 11.5;    // km por litro
    double preco = 6.79;      // R$ por litro

    double litros = distancia / consumo;
    double custo = litros * preco;

    printf("Distância: %d km\n", distancia);
    printf("Litros: %.2f\n", litros);
    printf("Custo da ida: R$ %.2f\n", custo);
    return 0;
}
