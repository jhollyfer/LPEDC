// Lista · Módulo 02 · Decisões
// Exercício P0202 · ★☆☆ · A multa da biblioteca

#include <stdio.h>

int main(void) {
    int dias;

    printf("Dias de atraso: ");
    scanf("%d", &dias);

    if (dias > 0) {
        printf("Multa: R$ %.2f\n", dias * 1.50);
    } else {
        printf("Sem multa.\n");
    }
    return 0;
}
