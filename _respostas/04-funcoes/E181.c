// 0031 · A pilha de chamadas
// Exercício E181 · ★☆☆

#include <stdio.h>

double quadrado(double x) {
    printf("    entra quadrado(x = %.2f)\n", x);
    double resultado = x * x;
    printf("    sai quadrado -> %.2f\n", resultado);
    return resultado;
}

double imc(double peso, double altura) {
    printf("  entra imc(peso = %.1f, altura = %.2f)\n", peso, altura);
    double area = quadrado(altura);
    double resultado = peso / area;
    printf("  sai imc -> %.1f\n", resultado);
    return resultado;
}

int main(void) {
    printf("main chama imc\n");
    double resultado = imc(72.0, 1.80);
    printf("IMC: %.1f\n", resultado);
    return 0;
}
