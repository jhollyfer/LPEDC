// 0007 · Aritmética
// Exercício E041 · ★★★
//
// O kit escolar custa R$ 20 de material mais R$ 5 de frete. Alguém criou um
// #define para o preço do kit e calculou o preço de 3 kits. Sem rodar, diga
// o que o programa mostra e por quê. Depois conserte mudando só o #define.
//
//   Saída esperada (depois de consertar):
//   3 kits: R$ 75
//
// Dicas:
// 1. O #define não calcula nada: ele cola o texto. Escreva a linha do printf
//    com o texto colado e aplique a precedência.
// 2. Toda macro que é uma conta deve vir entre parênteses.
// 3. Resposta esperada: mostra "3 kits: R$ 65", porque 3 * KIT vira
//    3 * 20 + 5 = 65. Conserto: #define KIT (20 + 5).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define KIT 20 + 5

int main(void) {
    printf("3 kits: R$ %d\n", 3 * KIT);
    return 0;
}
