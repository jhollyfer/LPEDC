// A077 · A viagem usando o módulo de conversão

#include <stdio.h>

#include "conversao.h" // aspas: procura primeiro na pasta deste arquivo

int main(void) {
    printf("30 °C = %.1f °F\n", celsius_para_fahrenheit(30));
    printf("100 km = %.1f milhas\n", km_para_milhas(100));
    printf("R$ 1000.00 = US$ %.2f\n", reais_para_dolares(1000, 5.40));
    return 0;
}
// Compilando à mão (o rodar faz isso sozinho):
//   gcc -std=c17 -Wall -Wextra A077.c conversao.c -o viagem
// Saída:
// 30 °C = 86.0 °F
// 100 km = 62.1 milhas
// R$ 1000.00 = US$ 185.19
