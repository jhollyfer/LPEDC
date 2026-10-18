// 0135 · Mochila fracionária
// Exercício E810 · ★★★
//
// Uma cooperativa vende grãos a granel e tem TRÊS caminhões, com 20, 35 e
// 30 kg livres (uma miniatura, para caber na tela). Os grãos, já em ordem
// decrescente de R$/kg:
//
//   pimenta 18 kg R$ 1080, cacau 25 kg R$ 1000, café 30 kg R$ 900,
//   soja 40 kg R$ 200
//
// Como tudo é fracionável, a melhor carga dos três juntos é a de UMA
// mochila com 20 + 35 + 30 = 85 kg. O desafio é distribuir: encha o
// caminhão 1 na ordem dos grãos; o grão que não couber inteiro tem o resto
// carregado no caminhão seguinte; e assim por diante. Mostre a carga e o
// valor de cada caminhão.
//
//   Saída esperada:
//   Caminhão 1 (20 kg): 18 kg de pimenta, 2 kg de cacau, R$ 1160.00
//   Caminhão 2 (35 kg): 23 kg de cacau, 12 kg de café, R$ 1280.00
//   Caminhão 3 (30 kg): 18 kg de café, 12 kg de soja, R$ 600.00
//   Total: R$ 3040.00
//
// Dicas:
// 1. Calcule a razão de cada grão ANTES de começar, num vetor à parte: o
//    kg de cada grão vai diminuir conforme ele é carregado.
// 2. Um índice i do grão da vez, que só avança quando o grão acaba
//    (kg[i] == 0). Para cada caminhão, um while (livre > 0 && i < n).
// 3. Resposta esperada: a saída acima. Repare que o cacau e o café ficaram
//    partidos entre dois caminhões; o total é o mesmo de uma mochila só de
//    85 kg.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    // já em ordem decrescente de R$/kg
    const char *grao[] = {"pimenta", "cacau", "café", "soja"};
    double kg[] = {18, 25, 30, 40};
    double valor[] = {1080, 1000, 900, 200};
    int n = 4;
    double caminhao[] = {20, 35, 30}; // capacidade de cada um, em kg
    int k = 3;
    (void)grao;
    (void)kg;
    (void)valor;
    (void)n;
    (void)caminhao;
    (void)k;

    return 0;
}
