// 0006 · scanf
// Exercício E032 · ★☆☆
//
// Resposta: (1) scanf("%d", calcado) entregava o valor de calcado (0) como
// se fosse um endereço; o scanf tentou escrever no endereço 0 e o programa
// quebrou (SEGV). O certo é &calcado. (2) peso é double: no scanf, %lf. Com
// %f, o scanf escreveria só 4 bytes, no formato de float.

#include <stdio.h>

int main(void) {
    int calcado = 0;
    double peso = 0;

    printf("Número do calçado: ");
    scanf("%d", &calcado);
    printf("Peso (kg): ");
    scanf("%lf", &peso);

    printf("Calçado %d, peso %.1f kg\n", calcado, peso);
    return 0;
}
