// 0051 · Passagem por referência
// Exercício E302 · ★☆☆

#include <stdio.h>

void converte(int total, int *horas, int *minutos) {
    *horas = total / 60;
    *minutos = total % 60;
}

int main(void) {
    int h, m;

    converte(135, &h, &m);
    printf("135 min = %d h %d min\n", h, m);
    converte(47, &h, &m);
    printf("47 min = %d h %d min\n", h, m);
    return 0;
}
