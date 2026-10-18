// 0140 · Mochila 0/1
// Exercício E840 · ★★★

#include <stdio.h>

#define N 6
#define PMAX 10 // kg
#define VMAX 8  // litros

int main(void) {
    int peso[N + 1] = {0, 3, 4, 2, 5, 1, 3};
    int volume[N + 1] = {0, 4, 2, 3, 3, 2, 3};
    int frete[N + 1] = {0, 25, 30, 18, 40, 9, 22};

    // t[i][p][v] = maior frete com os pacotes 1..i, até p kg e v litros
    static int t[N + 1][PMAX + 1][VMAX + 1]; // static: começa zerada (linha i = 0)
    for (int i = 1; i <= N; i++) {
        for (int p = 0; p <= PMAX; p++) {
            for (int v = 0; v <= VMAX; v++) {
                t[i][p][v] = t[i - 1][p][v];
                if (peso[i] <= p && volume[i] <= v) {
                    int com = frete[i] + t[i - 1][p - peso[i]][v - volume[i]];
                    if (com > t[i][p][v]) {
                        t[i][p][v] = com;
                    }
                }
            }
        }
    }
    printf("Frete máximo: R$ %d\n", t[N][PMAX][VMAX]);

    printf("Pacotes:");
    int p = PMAX, v = VMAX, pt = 0, vt = 0;
    for (int i = N; i >= 1; i--) {
        if (t[i][p][v] != t[i - 1][p][v]) {
            printf(" %d", i);
            p -= peso[i];
            v -= volume[i];
            pt += peso[i];
            vt += volume[i];
        }
    }
    printf("\nUsa %d kg e %d L\n", pt, vt);

    // conferência: força bruta pelos 2^N subconjuntos
    int melhor = 0;
    for (int m = 0; m < (1 << N); m++) {
        int sp = 0, sv = 0, sf = 0;
        for (int i = 1; i <= N; i++) {
            if (m & (1 << (i - 1))) {
                sp += peso[i];
                sv += volume[i];
                sf += frete[i];
            }
        }
        if (sp <= PMAX && sv <= VMAX && sf > melhor) {
            melhor = sf;
        }
    }
    printf("Força bruta: R$ %d\n", melhor);
    return 0;
}
