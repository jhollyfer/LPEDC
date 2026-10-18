// 0030 · Escopo e tempo de vida
// Exercício E180 · ★★★

#include <stdio.h>

static unsigned int estado = 1; // só este arquivo enxerga

void semear(unsigned int semente) {
    estado = semente;
}

int jogar_dado(void) {
    estado = (estado * 1103515245u + 12345u) % 2147483648u;
    return (int)(estado / 65536 % 6) + 1;
}

int main(void) {
    for (int rodada = 0; rodada < 2; rodada++) {
        semear(2026);
        for (int i = 0; i < 10; i++) {
            printf(i == 0 ? "%d" : " %d", jogar_dado());
        }
        printf("\n");
    }
    return 0;
}
