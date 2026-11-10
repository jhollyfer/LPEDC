// 0006 · scanf
// Exercício E034 · ★★☆

#include <stdio.h>

int main(void) {
    int quantidade = 0;
    char opcao = '?';

    scanf("%d", &quantidade);
    scanf(" %c", &opcao);

    printf("%d lanche(s), opção %c (código %d)\n", quantidade, opcao, opcao);
    return 0;
}
