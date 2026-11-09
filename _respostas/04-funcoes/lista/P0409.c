// Lista · Módulo 04 · Funções e modularização
// Exercício P0409 · ★☆☆ · Qual pizza compensa?

#include <stdio.h>

#define PI 3.14159265
#define AREA_CIRCULO(r) (PI * (r) * (r))

int main(void) {
    double broto = 30.00 / AREA_CIRCULO(25 / 2.0);
    double grande = 50.00 / AREA_CIRCULO(35 / 2.0);

    printf("Broto: R$ %.4f por cm2\n", broto);
    printf("Grande: R$ %.4f por cm2\n", grande);
    printf("Compensa mais: %s\n", grande < broto ? "grande" : "broto");
    return 0;
}
