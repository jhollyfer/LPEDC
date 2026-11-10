// 0016 · else if, if aninhado e o else pendurado
// Exercício E094 · ★★☆

#include <stdio.h>

int main(void) {
    double nota;
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
