// 0014 · if
// Exercício E080 · ★☆☆

#include <stdio.h>

int main(void) {
    double nota;
    printf("Nota da prova: ");
    if (scanf("%lf", &nota) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    nota = nota + 1; // bônus
    if (nota > 10) {
        nota = 10;
    }
    printf("Nota final: %.1f\n", nota);
    return 0;
}
