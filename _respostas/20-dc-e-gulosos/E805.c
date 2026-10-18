// 0135 · Mochila fracionária
// Exercício E805 · ★☆☆

#include <stdio.h>

int main(void) {
    // já em ordem decrescente de R$/kg
    const char *material[] = {"PET", "papelão", "vidro"};
    double peso[] = {300, 500, 800};  // kg no depósito
    double valor[] = {750, 400, 160}; // R$ pelo lote inteiro
    int n = 3;
    double livre = 1000;              // kg que o caminhão leva
    double total = 0;

    for (int i = 0; i < n && livre > 0; i++) {
        double leva = peso[i] <= livre ? peso[i] : livre;
        double ganho = valor[i] * leva / peso[i];
        printf("%.0f kg de %s: R$ %.2f\n", leva, material[i], ganho);
        livre -= leva;
        total += ganho;
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}
