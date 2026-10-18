// 0021 · else if, if aninhado e o else pendurado
// Exercício E124 · ★★☆
//
// Resposta: o else if para no primeiro Sim, e toda nota >= 9 também é >= 5.
// As condições precisam ir da mais restrita para a mais larga.

#include <stdio.h>

int main(void) {
    double nota;
    printf("Nota: ");
    if (scanf("%lf", &nota) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    if (nota >= 9) {
        printf("Conceito A\n");
    } else if (nota >= 7) {
        printf("Conceito B\n");
    } else if (nota >= 5) {
        printf("Conceito C\n");
    } else {
        printf("Conceito D\n");
    }
    return 0;
}
