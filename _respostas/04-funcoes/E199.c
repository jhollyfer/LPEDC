// 0034 · Módulos: .h, .c e compilação separada
// Exercício E199 · ★☆☆

#include <stdio.h>

// frete.h
#ifndef FRETE_H
#define FRETE_H

#define FRETE_GRATIS_ACIMA 200.0

double calcular_frete(double valor_compra, double peso_kg, int distancia_km);

#endif

// main.c
void mostrar_pedido(int numero, double valor, double peso, int km) {
    printf("Pedido %d (R$ %.2f, %.1f kg, %d km): frete R$ %.2f\n",
           numero, valor, peso, km, calcular_frete(valor, peso, km));
}

int main(void) {
    mostrar_pedido(1, 150.00, 2.0, 30);
    mostrar_pedido(2, 250.00, 5.0, 100);
    mostrar_pedido(3, 80.00, 1.0, 12);
    return 0;
}

// frete.c
static double taxa_por_km(int distancia_km) {
    return 0.20 * distancia_km;
}

double calcular_frete(double valor_compra, double peso_kg, int distancia_km) {
    if (valor_compra >= FRETE_GRATIS_ACIMA) {
        return 0;
    }
    return 10.00 + 1.50 * peso_kg + taxa_por_km(distancia_km);
}
