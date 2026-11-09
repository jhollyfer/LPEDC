// Lista · Módulo 02 · Decisões
// Exercício P0215 · ★★☆ · Que horas são em Manaus?

#include <stdio.h>

int main(void) {
    int hora = 23, minuto = 30; // horário de Brasília
    char fuso;
    int diferenca;

    printf("Fuso (F, B, M ou A): ");
    if (scanf(" %c", &fuso) != 1) {
        return 1;
    }

    switch (fuso) {
        case 'F':
            diferenca = 1;
            break;
        case 'B':
            diferenca = 0;
            break;
        case 'M':
            diferenca = -1;
            break;
        case 'A':
            diferenca = -2;
            break;
        default:
            printf("Fuso desconhecido.\n");
            return 1;
    }

    int hora_local = (hora + diferenca + 24) % 24;
    printf("Hora local: %02d:%02d\n", hora_local, minuto);
    return 0;
}
