// 0012 · Relacionais e a verdade em C
// Exercício E070 · ★★☆
//
// Resposta: 0.1 não tem representação exata em binário; 0.1 * 7 fica
// 0.70000000000000006661, e o == compara bit a bit com 0.7 (que também é
// aproximado, mas de outro jeito). Abaixo, os dois consertos.

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    // (a) tolerância
    double preco = 0.7;
    double pago = 0.1 * 7;
    bool exato = fabs(pago - preco) < 1e-9;
    printf("Pagou o valor exato? %d\n", exato);

    // (b) centavos em int: conta exata
    int preco_centavos = 70;
    int pago_centavos = 7 * 10;
    bool exato_centavos = pago_centavos == preco_centavos;
    printf("Pagou o valor exato? %d\n", exato_centavos);
    return 0;
}
