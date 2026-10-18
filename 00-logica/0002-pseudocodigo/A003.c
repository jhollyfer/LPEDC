// A003 · A média do semestre

#include <stdio.h>

int main(void) {
    double nota1 = 7.5;
    double nota2 = 5.5;
    double media = (nota1 + nota2) / 2;

    printf("Média: %.1f\n", media);
    if (media >= 6) {
        printf("Aprovado\n");
    } else {
        printf("Reprovado\n");
    }
    return 0;
}
// Saída:
// Média: 6.5
// Aprovado
