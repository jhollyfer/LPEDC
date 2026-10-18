// 0025 · Padrões de laço
// Exercício E145 · ★☆☆

#include <stdio.h>

int main(void) {
    double nota;
    double soma = 0.0;
    int acima = 0;

    for (int i = 1; i <= 5; i++) {
        printf("Nota %d: ", i);
        if (scanf("%lf", &nota) != 1) {
            return 1;
        }
        soma += nota;
        if (nota >= 6) {
            acima++;
        }
    }
    printf("Soma: %.1f\n", soma);
    printf("Média: %.1f\n", soma / 5);
    printf("Provas com 6 ou mais: %d\n", acima);
    return 0;
}
