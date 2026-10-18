// 0023 · switch, case, break e fall-through
// Exercício E137 · ★★★
//
// A pizzaria mostra o preço da pizza escolhida. Mas quem pede muçarela vê
// os quatro textos, inclusive "Opção inválida.". Rode com M, leia os avisos
// do compilador (eles são a pista) e conserte. Depois melhore: aceite também
// as letras minúsculas.
//
//   Pizza (M, C ou P): m
//   Muçarela: R$ 45.00
//
// Dicas:
// 1. O que faz a execução sair de um switch?
// 2. Para as minúsculas, empilhe: case 'M': case 'm':
// 3. Resposta esperada: falta um break no fim de cada case (o
//    -Wimplicit-fallthrough avisa "this statement may fall through").
//    Consertado: M ou m → só "Muçarela: R$ 45.00"; P → só
//    "Portuguesa: R$ 55.00"; X → só "Opção inválida.".
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    char pizza;
    printf("Pizza (M, C ou P): ");
    if (scanf(" %c", &pizza) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    switch (pizza) {
    case 'M':
        printf("Muçarela: R$ 45.00\n");
    case 'C':
        printf("Calabresa: R$ 50.00\n");
    case 'P':
        printf("Portuguesa: R$ 55.00\n");
    default:
        printf("Opção inválida.\n");
    }
    return 0;
}
