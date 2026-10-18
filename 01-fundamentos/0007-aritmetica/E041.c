// 0007 · Aritmética
// Exercício E041 · ★★★
//
// O kit escolar custa R$ 20 de material mais R$ 5 de frete. Alguém criou um
// #define para o preço do kit e calculou o preço de 3 kits e a parcela do
// kit em 5 vezes. O programa compila sem aviso, mas as duas contas saem
// erradas. Rode, veja os valores e conserte mudando só a linha do #define.
//
//   Saída esperada (depois de consertar):
//   3 kits: R$ 75
//   Kit em 5x: R$ 5
//
// Dicas:
// 1. O #define não calcula nada: ele cola o texto. Escreva cada printf com
//    o texto colado e aplique a precedência.
// 2. Toda macro que é uma conta deve vir entre parênteses.
// 3. Resposta esperada: antes, "3 kits: R$ 65" (3 * 20 + 5) e "Kit em 5x:
//    R$ 21" (20 + 5 / 5). Conserto: #define KIT (20 + 5), e as duas linhas
//    acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define KIT 20 + 5

int main(void) {
    printf("3 kits: R$ %d\n", 3 * KIT);
    printf("Kit em 5x: R$ %d\n", KIT / 5);
    return 0;
}
