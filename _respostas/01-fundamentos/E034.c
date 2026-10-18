// 0006 · scanf
// Exercício E034 · ★★☆
//
// Resposta: o %d leu o 3 e deixou na fila o '\n' do Enter. O %c não pula
// espaços nem Enters: leu o '\n' (código 10) e o V ficou sobrando. Com um
// espaço antes do %c, o scanf pula os espaços e Enters e pega o V.

#include <stdio.h>

int main(void) {
    int quantidade = 0;
    char opcao = '?';

    printf("Quantidade: ");
    scanf("%d", &quantidade);
    printf("Opção (V/A): ");
    scanf(" %c", &opcao);

    printf("%d lanche(s), opção %c (código %d)\n", quantidade, opcao, opcao);
    return 0;
}
