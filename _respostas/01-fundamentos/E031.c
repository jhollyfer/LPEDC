// 0006 · scanf
// Exercício E031 · ★☆☆

#include <stdio.h>

int main(void) {
    int idade;
    double altura;
    scanf("%d", &idade);
    scanf("%lf", &altura);

    printf("Você tem %d anos e %.2f m de altura.\n", idade, altura);
    return 0;
}
