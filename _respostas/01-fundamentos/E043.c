// 0008 · Conversão e cast
// Exercício E043 · ★☆☆

#include <stdio.h>

int main(void) {
    int nota1 = 7, nota2 = 8, nota3 = 10;

    double media = (double) (nota1 + nota2 + nota3) / 3;

    printf("Média: %.2f\n", media);
    return 0;
}
