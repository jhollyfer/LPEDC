// Lista · Módulo 03 · Laços
// Exercício P0315 · ★★☆ · A dívida do rotativo

#include <stdio.h>

int main(void) {
    const double INICIAL = 1000.00;
    double divida = INICIAL;
    int mes = 0;

    while (divida <= 2 * INICIAL) {
        divida *= 1.14;
        mes++;
        printf("Mês %d: R$ %.2f\n", mes, divida);
    }
    printf("A dívida dobrou em %d meses\n", mes);
    return 0;
}
