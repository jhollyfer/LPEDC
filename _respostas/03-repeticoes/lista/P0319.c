// Lista · Módulo 03 · Laços
// Exercício P0319 · ★★☆ · O desconto por quantidade

#include <stdio.h>

int main(void) {
    const double GALAO = 12.00;

    for (int qtd = 1; qtd <= 10; qtd++) {
        int desconto = 2 * qtd > 15 ? 15 : 2 * qtd;
        double total = qtd * GALAO * (100 - desconto) / 100.0;
        printf("%2d galão(ões): %2d%% -> R$ %6.2f\n", qtd, desconto, total);
    }
    return 0;
}
