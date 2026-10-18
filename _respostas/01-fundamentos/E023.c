// 0004 · Constantes
// Exercício E023 · ★★★
//
// Resposta: o original mostra "Comprimento: 60 m". O const não muda o tipo:
// pi é int, e guardar 3.14159 num int joga fora a parte fracionária sem
// aviso. Fica 2 * 3 * 10 = 60. O certo é um tipo real.

#include <stdio.h>

#define PI 3.14159

int main(void) {
    // jeito 1: const com o tipo certo
    const double pi = 3.14159;
    int raio = 10;
    printf("Comprimento: %.2f m\n", 2 * pi * raio);

    // jeito 2: #define (o compilador vê 2 * 3.14159 * raio)
    printf("Comprimento: %.2f m\n", 2 * PI * raio);
    return 0;
}
