// 0004 · Constantes
// Exercício E023 · ★★★

#include <stdio.h>

#define PI 3.14159

int main(void) {
    const double pi = 3.14159; // jeito 1: const com o tipo certo
    int raio = 10;

    printf("Comprimento (const):  %.2f m\n", 2 * pi * raio);
    printf("Comprimento (define): %.2f m\n", 2 * PI * raio); // jeito 2
    return 0;
}
