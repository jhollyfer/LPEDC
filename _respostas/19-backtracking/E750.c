// 0125 · Subconjuntos
// Exercício E750 · ★★★

#include <stdio.h>

#define N 3

void mostra_bits(int g) {
    for (int b = N - 1; b >= 0; b--) {
        printf("%d", (g >> b) & 1);
    }
}

int main(void) {
    int anterior = 0;
    mostra_bits(0);
    printf(" começo, tudo apagado\n");
    for (int m = 1; m < (1 << N); m++) {
        int g = m ^ (m >> 1);      // código de Gray
        int mudou = anterior ^ g;  // só um bit ligado
        int lampada = 0;
        while (!(mudou & (1 << lampada))) {
            lampada++;
        }
        mostra_bits(g);
        printf(" %s a lâmpada %d\n", (g & mudou) ? "liga" : "desliga", lampada);
        anterior = g;
    }
    return 0;
}
