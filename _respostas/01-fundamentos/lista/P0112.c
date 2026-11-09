// Lista · Módulo 01 · Fundamentos de C
// Exercício P0112 · ★★☆ · Os dígitos do medidor de luz

#include <stdio.h>

int main(void) {
    int leitura = 4827;

    int milhar = leitura / 1000;
    int centena = leitura / 100 % 10;
    int dezena = leitura / 10 % 10;
    int unidade = leitura % 10;

    printf("Dígitos: %d %d %d %d\n", milhar, centena, dezena, unidade);
    printf("Soma: %d\n", milhar + centena + dezena + unidade);
    printf("Produto: %d\n", milhar * centena * dezena * unidade);
    return 0;
}
