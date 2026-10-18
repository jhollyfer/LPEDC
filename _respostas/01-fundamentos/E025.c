// 0005 · printf
// Exercício E025 · ★☆☆

#include <stdio.h>

int main(void) {
    double nota = 8.75;
    int faltas = 3;
    char conceito = 'B';

    printf("Aluna: %s\n", "Júlia");
    printf("Nota: %.1f\n", nota);
    printf("Faltas: %02d\n", faltas);
    printf("Conceito: %c\n", conceito);
    return 0;
}
