// 0040 · Pré-processador: macros e #ifdef
// Exercício E237 · ★★☆
//
// O sistema da lanchonete tem dois erros, os dois nos #define. Um deles impede
// a compilação; o outro compila e dá a conta errada. Rode, leia o erro (que
// aponta para uma linha que parece certa), explique e conserte os dois.
//
//   Saída certa:
//   Desconto: R$ 3.50
//   Dois combos: R$ 60.00
//
// Dicas:
// 1. O que vem depois do nome, no #define, é colado INTEIRO no lugar, inclusive
//    um ";" perdido.
// 2. 2 * PRECO_COMBO vira 2 * 25 + 5.
// 3. Resposta esperada: tirar o ";" de "#define DESCONTO 0.10;" (dentro do
//    printf ele vira "preco * 0.10;", e o compilador reclama de um ")"
//    esperado) e escrever "#define PRECO_COMBO (25 + 5)": sem os parênteses,
//    dois combos davam 55.00.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define DESCONTO 0.10;
#define PRECO_COMBO 25 + 5

int main(void) {
    double preco = 35.00;

    printf("Desconto: R$ %.2f\n", preco * DESCONTO);
    printf("Dois combos: R$ %.2f\n", 2.0 * PRECO_COMBO);
    return 0;
}
