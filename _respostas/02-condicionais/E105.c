// 0018 · switch, case, break e fall-through
// Exercício E105 · ★★☆

#include <stdio.h>

int main(void) {
    int tecla;
    printf("Tecla: ");
    if (scanf("%d", &tecla) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    switch (tecla) {
    case 1:
        printf("Consultar saldo.\n");
        break;
    case 2:
        printf("Segunda via da fatura.\n");
        break;
    case 9:
        printf("Transferindo para um atendente...\n");
        break;
    default:
        printf("Opção inválida.\n");
        // fall through
    case 0:
        printf("Repetindo o menu.\n");
        break;
    }
    return 0;
}
