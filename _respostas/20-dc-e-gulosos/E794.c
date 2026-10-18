// 0133 · Algoritmos gulosos
// Exercício E794 · ★☆☆

#include <stdio.h>

int main(void) {
    int moedas[] = {100, 50, 25, 10, 5};
    int valor = 285; // centavos
    int total = 0;

    printf("Troco de %d centavos:\n", valor);
    for (int i = 0; i < 5; i++) {
        int quantas = valor / moedas[i]; // quantas cabem de uma vez
        valor %= moedas[i];              // o que sobra para as menores
        if (quantas > 0) {
            printf("  %d de %d\n", quantas, moedas[i]);
        }
        total += quantas;
    }
    printf("Total: %d moedas\n", total);
    return 0;
}
