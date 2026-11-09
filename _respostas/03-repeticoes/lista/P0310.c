// Lista · Módulo 03 · Laços
// Exercício P0310 · ★☆☆ · A parcela que sobrou

#include <stdio.h>

int main(void) {
    double parcela = 189.90;
    double total = 0.0;

    for (int i = 1; i <= 10; i++) { // de 1 a 10: exatamente 10 voltas
        printf("Parcela %d: R$ %.2f\n", i, parcela);
        total += parcela;
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}
