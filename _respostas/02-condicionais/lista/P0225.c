// Lista · Módulo 02 · Decisões
// Exercício P0225 · ★★★ · Choque de horários na agenda

#include <stdio.h>

int main(void) {
    int h1, m1, h2, m2, h3, m3, h4, m4;

    printf("Compromisso 1 (início fim): ");
    if (scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2) != 4) {
        return 1;
    }
    printf("Compromisso 2 (início fim): ");
    if (scanf("%d:%d %d:%d", &h3, &m3, &h4, &m4) != 4) {
        return 1;
    }

    int ini1 = h1 * 60 + m1, fim1 = h2 * 60 + m2;
    int ini2 = h3 * 60 + m3, fim2 = h4 * 60 + m4;

    int inicio_comum = ini1 > ini2 ? ini1 : ini2;
    int fim_comum = fim1 < fim2 ? fim1 : fim2;

    if (fim_comum > inicio_comum) {
        printf("Conflito de %d minutos\n", fim_comum - inicio_comum);
    } else {
        printf("Sem conflito\n");
    }
    return 0;
}
