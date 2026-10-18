// A007 · Uma constante feita de outras

#include <stdio.h>

#define TARIFA_CHEIA 4.90
#define DESCONTO_ESTUDANTE 0.5                          // estudante paga meia
#define TARIFA_MEIA (TARIFA_CHEIA * DESCONTO_ESTUDANTE) // um #define usando outros
#define CIDADE "Belo Horizonte"

int main(void) {
    const double recarga = 50.00; // const: tem tipo, tamanho e endereço

    printf("Ônibus de " CIDADE "\n"); // textos lado a lado viram um só
    printf("Inteira: R$ %.2f\n", TARIFA_CHEIA);
    printf("Meia:    R$ %.2f\n", TARIFA_MEIA);
    printf("Recarga: R$ %.2f\n", recarga);

    // o literal tem tamanho, decidido pelo jeito de escrever
    printf("recarga: %zu bytes; 4.90: %zu; 4.90f: %zu\n",
           sizeof recarga, sizeof 4.90, sizeof 4.90f);
    return 0;
}
// Saída:
// Ônibus de Belo Horizonte
// Inteira: R$ 4.90
// Meia:    R$ 2.45
// Recarga: R$ 50.00
// recarga: 8 bytes; 4.90: 8; 4.90f: 4
//
// Veja o que o compilador recebe: gcc -E A007.c | tail -14
// A linha do printf vira "Ônibus de " "Belo Horizonte" "\n" e a meia vira
// (4.90 * 0.5): os parênteses do #define TARIFA_MEIA vão junto.
