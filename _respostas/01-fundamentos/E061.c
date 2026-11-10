// 0011 · Juntando tudo
// Exercício E061 · ★☆☆

#include <stdio.h>
#include <math.h>

int main(void) {
    double peso, altura;
    scanf("%lf", &peso);
    scanf("%lf", &altura);

    double imc = peso / pow(altura, 2);
    printf("IMC: %.1f\n", imc);
    return 0;
}
