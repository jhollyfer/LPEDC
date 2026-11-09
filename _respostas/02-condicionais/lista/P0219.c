// Lista · Módulo 02 · Decisões
// Exercício P0219 · ★★☆ · Pedra, papel, tesoura, lagarto, Spock

#include <stdio.h>

int main(void) {
    int a, b;

    printf("Jogada de A (0 a 4): ");
    if (scanf("%d", &a) != 1) {
        return 1;
    }
    printf("Jogada de B (0 a 4): ");
    if (scanf("%d", &b) != 1) {
        return 1;
    }
    if (a < 0 || a > 4 || b < 0 || b > 4) {
        printf("Jogada inválida.\n");
        return 1;
    }

    switch ((a - b + 5) % 5) {
        case 0:
            printf("Empate.\n");
            break;
        case 1:
        case 2:
            printf("A vence!\n");
            break;
        default: // 3 ou 4
            printf("B vence!\n");
            break;
    }
    return 0;
}
