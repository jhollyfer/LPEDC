// 0011 · scanf
// Exercício E061 · ★☆☆

#include <stdio.h>

int main(void) {
    int idade;
    double altura;

    printf("Idade: ");
    scanf("%d", &idade);
    printf("Altura (m): ");
    scanf("%lf", &altura);

    printf("Você tem %d anos e %.2f m de altura.\n", idade, altura);
    return 0;
}
