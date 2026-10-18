// 0135 · Mochila fracionária
// Exercício E810 · ★★★

#include <stdio.h>

int main(void) {
    // já em ordem decrescente de R$/kg
    const char *grao[] = {"pimenta", "cacau", "café", "soja"};
    double kg[] = {18, 25, 30, 40};
    double valor[] = {1080, 1000, 900, 200};
    int n = 4;
    double caminhao[] = {20, 35, 30}; // capacidade de cada um, em kg
    int k = 3;

    double razao[4];
    for (int i = 0; i < n; i++) {
        razao[i] = valor[i] / kg[i];  // calcula antes de mexer em kg[]
    }

    double total = 0;
    int i = 0; // o grão da vez
    for (int c = 0; c < k; c++) {
        double livre = caminhao[c];
        double carga = 0;
        printf("Caminhão %d (%.0f kg):", c + 1, caminhao[c]);
        while (livre > 0 && i < n) {
            double leva = kg[i] <= livre ? kg[i] : livre;
            carga += razao[i] * leva;
            printf(" %.0f kg de %s,", leva, grao[i]);
            livre -= leva;
            kg[i] -= leva;            // o que sobrou deste grão vai no próximo
            if (kg[i] == 0) {
                i++;
            }
        }
        printf(" R$ %.2f\n", carga);
        total += carga;
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}
