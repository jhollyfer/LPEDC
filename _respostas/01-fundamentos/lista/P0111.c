// Lista · Módulo 01 · Fundamentos de C
// Exercício P0111 · ★★☆ · Quanto tempo leva o backup

#include <stdio.h>

int main(void) {
    int total = 200000;

    int dias = total / 86400;
    int resto = total % 86400;
    int horas = resto / 3600;
    resto = resto % 3600;
    int minutos = resto / 60;
    int segundos = resto % 60;

    printf("%d s = %d dia(s), %d h, %d min e %d s\n", total, dias, horas, minutos, segundos);
    return 0;
}
