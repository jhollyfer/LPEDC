// 0028 · Funções
// Exercício E166 · ★★☆

#include <math.h>
#include <stdio.h>

double tarifa(double horas);

int main(void) {
    double c1 = tarifa(1.5);
    double c2 = tarifa(3.2);
    double c3 = tarifa(12.0);

    printf("Carro 1 (1.5 h): R$ %.2f\n", c1);
    printf("Carro 2 (3.2 h): R$ %.2f\n", c2);
    printf("Carro 3 (12.0 h): R$ %.2f\n", c3);
    printf("Total do dia: R$ %.2f\n", c1 + c2 + c3);
    return 0;
}

double tarifa(double horas) {
    if (horas <= 2) {
        return 5.00;
    }
    double valor = 5.00 + 2.00 * ceil(horas - 2);
    return valor > 20.00 ? 20.00 : valor;
}
