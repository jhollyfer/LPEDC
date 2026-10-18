// 0019 · Juntando tudo: a conta de luz
// Exercício E109 · ★☆☆

#include <stdio.h>

int main(void) {
    double peso, altura;
    printf("Peso e altura: ");
    if (scanf("%lf %lf", &peso, &altura) != 2 || altura <= 0) {
        printf("Dados inválidos.\n");
        return 1;
    }

    double imc = peso / (altura * altura);
    printf("IMC: %.2f\n", imc);
    if (imc < 18.5) {
        printf("Abaixo do peso\n");
    } else if (imc < 25) {
        printf("Peso normal\n");
    } else if (imc < 30) {
        printf("Sobrepeso\n");
    } else {
        printf("Obesidade\n");
    }
    return 0;
}
