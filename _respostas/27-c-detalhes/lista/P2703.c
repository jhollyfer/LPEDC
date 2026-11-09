// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2703 · ★☆☆ · A conta de luz

#include <stdio.h>

int main(void) {
    int consumo = 250;  // kWh
    int tarifa = 80;    // centavos por kWh
    int bandeira = 10;  // centavos por kWh
    int taxa = 1500;    // centavos

    int total = consumo * (tarifa + bandeira) + taxa;
    printf("total: R$ %.2f\n", total / 100.0);

    int pct = 100 * bandeira / (tarifa + bandeira);
    printf("bandeira: %d%% do preço do kWh\n", pct);
    return 0;
}
