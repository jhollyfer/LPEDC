// Lista · Módulo 02 · Decisões
// Exercício P0223 · ★★★ · O placar do set de vôlei

#include <stdio.h>

int main(void) {
    int a, b;

    printf("Placar (A B): ");
    if (scanf("%d %d", &a, &b) != 2) {
        return 1;
    }

    int maior = a > b ? a : b;
    int menor = a > b ? b : a;
    int diferenca = maior - menor;

    if (menor < 0) {
        printf("Placar impossível\n");
    } else if (maior < 25 || diferenca < 2) {
        printf("Set em andamento\n");
    } else if (maior > 25 && diferenca > 2) {
        printf("Placar impossível\n");
    } else {
        printf("Set do time %c (%d x %d)\n", a > b ? 'A' : 'B', a, b);
    }
    return 0;
}
