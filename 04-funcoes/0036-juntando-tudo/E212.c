// 0036 · Juntando tudo: o caixa da lanchonete
// Exercício E212 · ★☆☆
//
// Refatore o programa abaixo: a mesma conta e a mesma classificação aparecem
// três vezes. Crie "double imc(double peso, double altura)" e
// "void mostrar_imc(int pessoa, double peso, double altura)", e deixe o main
// com três chamadas. A saída não pode mudar.
//
//   Saída esperada:
//   Pessoa 1: IMC 22.9 (normal)
//   Pessoa 2: IMC 27.8 (acima)
//   Pessoa 3: IMC 17.6 (abaixo)
//
// Dicas:
// 1. Copie um bloco, troque os números pelos parâmetros, e apague os outros dois.
// 2. mostrar_imc chama imc. Quem decide "abaixo/normal/acima" pode ser uma
//    terceira função, se você quiser.
// 3. Resposta esperada: a mesma saída, com o main de três linhas. Se a regra
//    mudar (o limite de 25 virar 24.9), agora você muda num lugar só.
//
// Escreva sua resposta abaixo (refatore o código):

#include <stdio.h>

int main(void) {
    double imc1 = 70.0 / (1.75 * 1.75);
    printf("Pessoa 1: IMC %.1f ", imc1);
    if (imc1 < 18.5) {
        printf("(abaixo)\n");
    } else if (imc1 < 25) {
        printf("(normal)\n");
    } else {
        printf("(acima)\n");
    }

    double imc2 = 85.0 / (1.75 * 1.75);
    printf("Pessoa 2: IMC %.1f ", imc2);
    if (imc2 < 18.5) {
        printf("(abaixo)\n");
    } else if (imc2 < 25) {
        printf("(normal)\n");
    } else {
        printf("(acima)\n");
    }

    double imc3 = 52.0 / (1.72 * 1.72);
    printf("Pessoa 3: IMC %.1f ", imc3);
    if (imc3 < 18.5) {
        printf("(abaixo)\n");
    } else if (imc3 < 25) {
        printf("(normal)\n");
    } else {
        printf("(acima)\n");
    }
    return 0;
}
