// 0036 · Juntando tudo: o caixa da lanchonete
// Exercício E212 · ★☆☆

#include <stdio.h>

double imc(double peso, double altura) {
    return peso / (altura * altura);
}

void mostrar_imc(int pessoa, double peso, double altura) {
    double valor = imc(peso, altura);
    printf("Pessoa %d: IMC %.1f ", pessoa, valor);
    if (valor < 18.5) {
        printf("(abaixo)\n");
    } else if (valor < 25) {
        printf("(normal)\n");
    } else {
        printf("(acima)\n");
    }
}

int main(void) {
    mostrar_imc(1, 70.0, 1.75);
    mostrar_imc(2, 85.0, 1.75);
    mostrar_imc(3, 52.0, 1.72);
    return 0;
}
