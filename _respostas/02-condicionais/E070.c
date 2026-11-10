// 0012 · Relacionais e a verdade em C
// Exercício E070 · ★★☆

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    // (a) tolerância
    double preco = 0.7;
    double pago = 0.1 * 7;
    printf("pago = %.20f\n", pago);
    bool exato = fabs(pago - preco) < 1e-9;
    printf("Pagou o valor exato? %d\n", exato);

    // (b) centavos em int
    int preco_centavos = 70;
    int pago_centavos = 7 * 10;
    bool exato_centavos = pago_centavos == preco_centavos;
    printf("Pagou o valor exato? %d\n", exato_centavos);
    return 0;
}
