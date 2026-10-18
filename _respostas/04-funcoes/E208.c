// 0035 · Pré-processador: macros e #ifdef
// Exercício E208 · ★★☆

#include <stdio.h>

#define MODO_TESTE // apague para ver só o total

int main(void) {
    double valor = 1000.00;
    int vezes = 4;
    double total = 0;

    for (int k = 1; k <= vezes; k++) {
        double parcela = valor / vezes * (1 + 0.02 * k);
        total += parcela;
#ifdef MODO_TESTE
        printf("[teste] parcela %d: %.2f\n", k, parcela);
#endif
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}
