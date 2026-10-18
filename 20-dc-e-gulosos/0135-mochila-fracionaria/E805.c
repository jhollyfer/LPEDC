// 0135 · Mochila fracionária
// Exercício E805 · ★☆☆
//
// A cooperativa de reciclagem vende para uma usina, e o caminhão leva 1000
// kg. No depósito há três lotes, já em ordem decrescente de R$/kg:
//
//   PET: 300 kg, R$ 750 o lote
//   papelão: 500 kg, R$ 400 o lote
//   vidro: 800 kg, R$ 160 o lote
//
// Escreva o laço da mochila fracionária: leve cada lote inteiro enquanto
// couber e, no primeiro que não couber, só a parte que completa o
// caminhão. Mostre o que vai de cada material e o total.
//
//   Saída esperada:
//   300 kg de PET: R$ 750.00
//   500 kg de papelão: R$ 400.00
//   200 kg de vidro: R$ 40.00
//   Total: R$ 1190.00
//
// Dicas:
// 1. leva = o menor entre peso[i] e livre. O valor levado é proporcional:
//    valor[i] * leva / peso[i].
// 2. O laço para quando livre chega a 0 (ou acabam os lotes).
// 3. Resposta esperada: a saída acima. O vidro rende R$ 0,20/kg, então os
//    200 kg dele valem R$ 40.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    // já em ordem decrescente de R$/kg
    const char *material[] = {"PET", "papelão", "vidro"};
    double peso[] = {300, 500, 800};  // kg no depósito
    double valor[] = {750, 400, 160}; // R$ pelo lote inteiro
    int n = 3;
    double livre = 1000;              // kg que o caminhão leva
    (void)material;
    (void)peso;
    (void)valor;
    (void)n;
    (void)livre;

    return 0;
}
