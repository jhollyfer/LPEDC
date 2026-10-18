// 0018 · switch, case, break e fall-through
// Exercício E108 · ★★★

#include <stdio.h>

int main(void) {
    int pacote;
    printf("Pacote (1 a 3): ");
    if (scanf("%d", &pacote) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    double total = 0;
    switch (pacote) {
    case 3:
        printf("Cera: R$ 25.00\n");
        total += 25;
        // fall through
    case 2:
        printf("Aspiração: R$ 15.00\n");
        total += 15;
        // fall through
    case 1:
        printf("Lavagem: R$ 30.00\n");
        total += 30;
        break;
    default:
        printf("Pacote inválido.\n");
        return 1;
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}
