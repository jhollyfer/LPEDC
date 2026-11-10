// 0007 · Aritmética
// Exercício E040 · ★★☆

#include <stdio.h>

int main(void) {
    int nota1 = 8, nota2 = 7, nota3 = 8;

    double media1 = (nota1 + nota2 + nota3) / 3.0;
    double media2 = (double)(nota1 + nota2 + nota3) / 3;

    printf("Média 1: %.2f\n", media1);
    printf("Média 2: %.2f\n", media2);
    return 0;
}
