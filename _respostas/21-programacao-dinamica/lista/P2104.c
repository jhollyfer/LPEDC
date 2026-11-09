// Lista · Módulo 21 · Programação dinâmica
// Exercício P2104 · ★☆☆ · As fichas do fliperama

#include <stdio.h>

#define T 4
#define ALVO 11
#define INF 1000000

int main(void) {
    const int pacote[T] = {1, 5, 6, 9};
    int min[ALVO + 1], ult[ALVO + 1];
    min[0] = 0;
    ult[0] = 0;
    for (int v = 1; v <= ALVO; v++) {
        min[v] = INF;
        ult[v] = 0;
        for (int i = 0; i < T; i++) {
            int p = pacote[i];
            if (p <= v && min[v - p] + 1 < min[v]) {
                min[v] = min[v - p] + 1;
                ult[v] = p;
            }
        }
    }
    printf("Mínimo para %d fichas: %d pacotes\n", ALVO, min[ALVO]);
    printf("Compra:");
    for (int v = ALVO; v > 0 && ult[v] > 0; v -= ult[v]) {
        printf(" %d", ult[v]);
    }
    printf("\n");
    return 0;
}
