// 0022 · Ternário: condição ? a : b
// Exercício E127 · ★☆☆
//
// Refatore: troque o if/else abaixo por UMA linha com o operador ternário.
// A saída tem que continuar igual.
//
//   Idade: 15
//   Ingresso: R$ 20.00
//
// Dicas:
// 1. O formato é: variavel = condição ? valor1 : valor2;
// 2. A declaração pode ir junto: double preco = ...;
// 3. Resposta esperada: double preco = idade >= 18 ? 40.0 : 20.0;
//    15 → 20.00; 30 → 40.00.
//
// Escreva sua resposta abaixo (refatore o código):

#include <stdio.h>

int main(void) {
    int idade;
    printf("Idade: ");
    if (scanf("%d", &idade) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    double preco;
    if (idade >= 18) {
        preco = 40.0;
    } else {
        preco = 20.0;
    }
    printf("Ingresso: R$ %.2f\n", preco);
    return 0;
}
