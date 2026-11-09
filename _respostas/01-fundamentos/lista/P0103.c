// Lista · Módulo 01 · Fundamentos de C
// Exercício P0103 · ★☆☆ · Minutos do plano de celular

#include <stdio.h>

int main(void) {
    int total = 437;
    int horas = total / 60;
    int minutos = total % 60;

    printf("%d minutos = %d h e %d min\n", total, horas, minutos);
    return 0;
}
