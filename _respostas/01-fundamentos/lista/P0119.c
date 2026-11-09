// Lista · Módulo 01 · Fundamentos de C
// Exercício P0119 · ★★☆ · A caixa d'água da casa

#include <stdio.h>

int main(void) {
    const double PI = 3.14159265;
    double raio = 0.6, altura = 1.2;
    int gasto_diario = 180;

    double volume = PI * raio * raio * altura;
    int litros = (int)(volume * 1000);

    printf("Volume: %.4f m3\n", volume);
    printf("Capacidade: %d litros\n", litros);
    printf("Dura %d dias completos e sobram %d litros\n", litros / gasto_diario, litros % gasto_diario);
    return 0;
}
