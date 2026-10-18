// 0013 · Conversão e cast
// Exercício E075 · ★★☆
//
// Resposta: em votos / total * 100, a conta começa por 47 / 130, divisão
// inteira que dá 0; 0 * 100 = 0. Em 100 * votos / total, 4700 / 130 dá 36:
// a parte inteira está certa, mas os decimais foram cortados. Com 100.0 na
// frente, a conta toda vira real: 36.15.

#include <stdio.h>

int main(void) {
    int votos = 47;
    int total = 130;

    printf("Marta: %.2f%% dos votos\n", 100.0 * votos / total);
    return 0;
}
