// Lista · Módulo 02 · Decisões
// Exercício P0201 · ★☆☆ · O rodízio de placas

#include <stdio.h>

int main(void) {
    int numero = 4827;
    int final = numero % 10;

    printf("Final da placa: %d\n", final);
    switch (final) {
        case 1:
        case 2:
            printf("Rodízio na segunda-feira\n");
            break;
        case 3:
        case 4:
            printf("Rodízio na terça-feira\n");
            break;
        case 5:
        case 6:
            printf("Rodízio na quarta-feira\n");
            break;
        case 7:
        case 8:
            printf("Rodízio na quinta-feira\n");
            break;
        default: // 9 e 0
            printf("Rodízio na sexta-feira\n");
            break;
    }
    return 0;
}
