// Lista · Módulo 08 · Tipos compostos
// Exercício P0802 · ★☆☆ · A que horas o voo chega

#include <stdio.h>

typedef struct {
    int h, m;
} Horario;

Horario somar(Horario ini, int minutos, int *dias) {
    int total = ini.h * 60 + ini.m + minutos;
    *dias = total / (24 * 60);
    total %= 24 * 60;
    Horario r = {total / 60, total % 60};
    return r;
}

int main(void) {
    const char *origem[3] = {"Manaus", "Belém", "Rio Branco"};
    Horario partida[3] = {{22, 45}, {6, 10}, {23, 30}};
    int duracao[3] = {230, 95, 1500};

    for (int i = 0; i < 3; i++) {
        int dias;
        Horario c = somar(partida[i], duracao[i], &dias);
        printf("%s %02d:%02d + %d min = %02d:%02d", origem[i], partida[i].h,
               partida[i].m, duracao[i], c.h, c.m);
        if (dias > 0) {
            printf(" (+%d dia%s)", dias, dias > 1 ? "s" : "");
        }
        printf("\n");
    }
    return 0;
}
