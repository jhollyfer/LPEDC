// 0023 · switch, case, break e fall-through
// Exercício E137 · ★★★
//
// Resposta: nenhum case tinha break, então a execução entrava no case certo e
// descia por todos os de baixo, até o default.

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
    case 'm':
        printf("Muçarela: R$ 45.00\n");
        break;
    case 'C':
    case 'c':
        printf("Calabresa: R$ 50.00\n");
        break;
    case 'P':
    case 'p':
        printf("Portuguesa: R$ 55.00\n");
        break;
    default:
        printf("Opção inválida.\n");
    }
    return 0;
}
