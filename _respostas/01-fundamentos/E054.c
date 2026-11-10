// 0009 · Atribuição, ++ e --
// Exercício E054 · ★★★

#include <stdio.h>

int main(void) {
    int casa = 2;
    int visitante = 5;

    casa += visitante;            // casa = 7 (a soma dos dois)
    visitante = casa - visitante; // 7 - 5 = 2
    casa -= visitante;            // 7 - 2 = 5

    printf("Casa %d x %d Visitante\n", casa, visitante);
    return 0;
}
