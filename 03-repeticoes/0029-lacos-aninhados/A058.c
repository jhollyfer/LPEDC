// A058 · Triângulos de asteriscos: o de dentro depende do de fora

#include <stdio.h>

int main(void) {
    int altura = 5;

    // linha 1 tem 1 asterisco, linha 2 tem 2... o limite de dentro é "linha"
    for (int linha = 1; linha <= altura; linha++) {
        for (int col = 1; col <= linha; col++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");

    // de cabeça para baixo: espaços à esquerda, depois os asteriscos
    for (int linha = altura; linha >= 1; linha--) {
        for (int esp = 1; esp <= altura - linha; esp++) {
            printf(" ");
        }
        for (int col = 1; col <= linha; col++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
// Saída:
// *
// **
// ***
// ****
// *****
//
// *****
//  ****
//   ***
//    **
//     *
