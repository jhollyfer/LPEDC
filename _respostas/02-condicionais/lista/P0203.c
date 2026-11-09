// Lista · Módulo 02 · Decisões
// Exercício P0203 · ★☆☆ · O ingresso do sócio-torcedor

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    const double INGRESSO = 60.00;
    bool carla_socia = true;
    bool beto_socio = false;

    double preco_carla = carla_socia ? INGRESSO / 2 : INGRESSO;
    double preco_beto = beto_socio ? INGRESSO / 2 : INGRESSO;

    printf("Carla paga R$ %.2f\n", preco_carla);
    printf("Beto paga R$ %.2f\n", preco_beto);
    return 0;
}
