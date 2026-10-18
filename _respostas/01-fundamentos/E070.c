// 0012 · Aritmética
// Exercício E070 · ★★☆
//
// Resposta: na média 1, (8 + 7 + 8) / 3 é 23 / 3 entre dois int: dá 7, e
// só depois vira 7.0. Na média 2, a precedência faz 8 + 7 + (8 / 3.0) =
// 17.67. O conserto é dividir a soma inteira por 3.0.

#include <stdio.h>

int main(void) {
    int nota1 = 8, nota2 = 7, nota3 = 8;

    double media1 = (nota1 + nota2 + nota3) / 3.0;
    double media2 = (nota1 + nota2 + nota3) / 3.0;

    printf("Média 1: %.2f\n", media1);
    printf("Média 2: %.2f\n", media2);
    return 0;
}
