// 0023 · switch, case, break e fall-through
// Exercício E133 · ★☆☆

#include <stdio.h>

int main(void) {
    int dia;
    printf("Dia (1 a 7): ");
    if (scanf("%d", &dia) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    switch (dia) {
    case 1:
        printf("Domingo\n");
        break;
    case 2:
        printf("Segunda-feira\n");
        break;
    case 3:
        printf("Terça-feira\n");
        break;
    case 4:
        printf("Quarta-feira\n");
        break;
    case 5:
        printf("Quinta-feira\n");
        break;
    case 6:
        printf("Sexta-feira\n");
        break;
    case 7:
        printf("Sábado\n");
        break;
    default:
        printf("Dia inválido.\n");
    }
    return 0;
}
