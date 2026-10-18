// 0013 · Conversão e cast
// Exercício E076 · ★★☆
//
// Na balança do açougue, a picanha custa R$ 45.90 o quilo. O programa
// calcula o preço de 600 gramas, mas mostra R$ 0.00. Ele compila sem aviso.
// Descubra o erro e conserte sem mudar o tipo de nenhuma variável.
//
//   Saída esperada (depois de consertar):
//   600 g: R$ 27.54
//
// Dicas:
// 1. Calcule gramas / 1000 sabendo que os dois são int.
// 2. Conta da esquerda para a direita: o zero aparece antes da multiplicação.
// 3. Resposta esperada: 600 / 1000 é divisão inteira e dá 0; 0 * 45.90 = 0.
//    Conserto: gramas / 1000.0 * preco_kg (ou multiplicar antes:
//    gramas * preco_kg / 1000). Resultado: R$ 27.54.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int gramas = 600;
    double preco_kg = 45.90;

    double preco = gramas / 1000 * preco_kg;

    printf("%d g: R$ %.2f\n", gramas, preco);
    return 0;
}
