// Lista · Módulo 03 · Laços
// Exercício P0302 · ★☆☆ · O desafio do cofrinho

#include <stdio.h>

int main(void) {
    int dia = 1;
    int total = 0;

    while (dia <= 30) {
        total += dia;
        if (dia % 10 == 0) {
            printf("Dia %d: R$ %d\n", dia, total);
        }
        dia++;
    }
    printf("Total em 30 dias: R$ %d\n", total);
    return 0;
}
