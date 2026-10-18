// 0015 · math.h
// Exercício E089 · ★★★
//
// Resposta: (1) 1 / 3 é divisão inteira e vale 0; pow(27, 0) = 1. Com
// 1.0 / 3, sai a raiz cúbica. (2) abs é a função dos int (do stdlib.h): o
// -2.75 vira -2 antes, e o resultado é 2; o gcc avisa "using integer
// absolute value function 'abs'". Para real, fabs. (3) 7 / 2 já dá 3 antes
// de chegar no ceil, e não há o que arredondar; com 7 / 2.0 = 3.5, o ceil
// dá 4.

#include <stdio.h>
#include <math.h>

int main(void) {
    double aresta = pow(27, 1.0 / 3);
    double falta = fabs(-2.75);
    double mesas = ceil(7 / 2.0);

    printf("Aresta: %.2f m\n", aresta);
    printf("Faltam %.2f graus\n", falta);
    printf("Mesas: %.0f\n", mesas);
    return 0;
}
